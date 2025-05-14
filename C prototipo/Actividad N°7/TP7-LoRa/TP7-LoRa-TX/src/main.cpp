#include <Arduino.h>
#include <SPI.h>
#include <lmic.h>
#include <hal/hal.h>
#include <DHT.h>

//==========================
// Configuración para Argentina
//==========================
// Región: Argentina
// Denominación: AU915
// Banda ISM: 915-928 MHz
// Regulado por: ENACOM
// Restricción TX: 400 ms (Opcional)
// Tamaño de carga útil (Payload): 11 a 242 bytes
// Spreading Factors: SF7 a SF10
// Velocidad de datos: 0,976 kbps a 12,5 kbps
// Potencia máxima TX: +30 dBm
//==========================

//==========================
// PINES LoRa SX1278
//==========================
const lmic_pinmap lmic_pins = {
    .nss  = 5,                                      // .nss: [NSEL] chip‐selec
    .rxtx = LMIC_UNUSED_PIN,                        // .rxtx: no usado
    .rst  = LMIC_UNUSED_PIN,                        // .rst:[SND] no usamos pin de reset (SDN queda unido con GND)
    .dio  = {4, LMIC_UNUSED_PIN, LMIC_UNUSED_PIN},  // .dio[0]:[NIRQ] DIO0 para interrupciones RX/TX 
};

//────────────────────────────────────────────────────────────
//  DHT11 (sensado temperatura/humedad)
//────────────────────────────────────────────────────────────
#define DHTPIN   17
#define DHTTYPE  DHT11
DHT dht(DHTPIN, DHTTYPE);

//────────────────────────────────────────────────────────────
//  Parámetros ABP
//────────────────────────────────────────────────────────────
static const u4_t  DEVADDR = 0x26011BDA;        // DevAddr asignado
static const u1_t  NWKSKEY[16] = {              // Network Session Key
  0xAA,0xBB,0xCC,0xDD, 0xEE,0xFF,0x00,0x11,
  0x22,0x33,0x44,0x55, 0x66,0x77,0x88,0x99
};
static const u1_t  APPSKEY[16] = {              // App Session Key
  0x11,0x22,0x33,0x44, 0x55,0x66,0x77,0x88,
  0x99,0xAA,0xBB,0xCC, 0xDD,0xEE,0xFF,0x00
};

//────────────────────────────────────────────────────────────
//  Job para agendar envíos periódicos
//────────────────────────────────────────────────────────────
static osjob_t sendjob;
const unsigned   TX_INTERVAL = 30;

//────────────────────────────────────────────────────────────
//  Función de “send”
//────────────────────────────────────────────────────────────
void do_send(osjob_t* j) {
  if (LMIC.opmode & OP_TXRXPEND) {                      // Si ya hay un TX pendiente, lo saltamos
    Serial.println(F("TX pendiente, salto envío"));
  } else {                                              // Leer DHT11
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    
    int16_t ti = isnan(t) ? 0 : (int16_t)(t * 10);      // Empaquetar en 4 bytes (x10, entero con signo)
    int16_t hi = isnan(h) ? 0 : (int16_t)(h * 10);
    uint8_t payload[4] = {
      highByte(ti), lowByte(ti),
      highByte(hi), lowByte(hi)
    };

    
    LMIC_setTxData2(1, payload, sizeof(payload), 0);    // Enviar en puerto lógicos 1, unconfirmed
    Serial.printf("Datos DHT11 enviados: [%.1f°C | %.1f%%]\n", t, h);
  }
  // Re-agendar próximo envío
  os_setTimedCallback(j, os_getTime() + sec2osticks(TX_INTERVAL), do_send);
}

//────────────────────────────────────────────────────────────
//  Callbacks 
//────────────────────────────────────────────────────────────
void onEvent(ev_t ev) { /* vacio en ABP */ }

void setup() {
  Serial.begin(115200);
  while (!Serial);
  dht.begin();

  
  os_init();                                        // Inicializa LMIC y limpia estado
  LMIC_reset();
  LMIC_setSession(0x1, DEVADDR, NWKSKEY, APPSKEY);  // Configura sesión ABP:
  LMIC_setLinkCheckMode(0);                         // Desactiva verificación de enlace
  DR_SF7 = 0.976 kbps; DR_SF10 = ~0.244 kbps        // Configura DataRate (SF7–SF10) y potencia TX
  LMIC_setDrTxpow(DR_SF7, 30);                      // La según alcance/throughput deseado
  do_send(&sendjob);                                // Llama a la función de envío                    
}

void loop() {
  os_runloop_once();
}