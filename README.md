# ESP32-S3 Multitasking Project  
**Nama:** Andika Nugraha  
**NIM:** 3223600010  
**Kelas:** 3 D4 Teknik Komputer A  
**Mata Kuliah:** Sistem Embedded  

## Konsep Proyek  
Eksperimen ini mengimplementasikan **multitasking dan dual-core processing** pada mikrokontroler **ESP32-S3** menggunakan FreeRTOS.  
Tujuannya untuk menguji performa dan kestabilan berbagai periferal saat dijalankan di Core 0 dan Core 1.

---

## Pinout dan Komponen

| Komponen           | Pin ESP32-S3 | Keterangan   |
| ------------------ | ------------ | ------------ |
| LED                | 15           | Output       |
| Buzzer             | 4            | Output       |
| Push Button 1      | 18           | Input        |
| Push Button 2      | 19           | Input        |
| Potensiometer      | 36           | Analog input |
| OLED SDA           | 8            | I2C data     |
| OLED SCL           | 9            | I2C clock    |
| Rotary Encoder CLK | 10           | Input A      |
| Rotary Encoder DT  | 11           | Input B      |
| Rotary Encoder SW  | 12           | Push switch  |
| Servo PWM          | 42           | Output PWM   |
| Stepper B-         | 37           | Output coil  |
| Stepper B+         | 38           | Output coil  |
| Stepper A+         | 39           | Output coil  |
| Stepper A-         | 40           | Output coil  |

> Diagram lengkap tersedia pada file `diagram.json` di WokWi.

---

##  Tujuan Percobaan

- Menguji fungsi masing-masing peripheral pada ESP32-S3.  
- Mengamati perbedaan performa task di Core 0 dan Core 1.  
- Mengetahui kestabilan akses I/O, PWM, ADC, dan I²C dalam lingkungan multitasking.

---

## Langkah Percobaan per Peripheral

### 1. LED Test
**Tujuan:** Menguji output digital.  
**File:** `led_test.ino`  
- LED di GPIO15 berkedip setiap 500 ms.  
- Jalankan di Core 0 lalu ubah ke Core 1.  
- Bandingkan kestabilan waktu kedip.

---

### 2. Buzzer Test
**Tujuan:** Menguji output digital (bunyi).  
**File:** `buzzer.ino`  
- Buzzer aktif 300 ms tiap 1 detik.  
- Bandingkan timing antar core.

---

### 3. Push Button Test
**Tujuan:** Menguji input digital dengan pull-up.  
**File:** `button.ino`  
- Tekan tombol 1 (GPIO18) atau 2 (GPIO19).  
- LED GPIO15 menyala saat tombol ditekan.  
- Ubah core task dan amati respon.

---

### 4. Potensiometer Test
**Tujuan:** Membaca nilai analog.  
**File:** `potentio.ino`  
- Putar knob potensiometer.  
- Nilai ADC (0–4095) muncul di Serial Monitor.  
- Bandingkan pembacaan di Core 0 dan Core 1.

---

### 5. OLED Display Test
**Tujuan:** Menampilkan teks pada OLED SSD1306.  
**File:** `oled.ino`  
- Menampilkan teks *“OLED Task running on Core ...”* di layar.  
- Coba di Core 0 dan Core 1, amati kestabilannya.

---

### 6. Rotary Encoder Test
**Tujuan:** Membaca arah dan langkah putaran.  
**File:** `encoder.ino`  
- Putar knob searah atau berlawanan jarum jam.  
- Nilai counter tampil di Serial Monitor.  
- Uji kecepatan respon antar core.

---

### 7. Servo Test
**Tujuan:** Menguji kontrol PWM.  
**File:** `servo.ino`  
- Servo bergerak 0° → 180° → 0° berulang.  
- Jalankan di Core 0 dan Core 1, catat kestabilannya.

---

### 8. Stepper Motor Test
**Tujuan:** Menguji urutan coil stepper.  
**File:** `stepper.ino`  
- Motor berputar searah dan berlawanan jarum jam.  
- Bandingkan kelancaran di Core 0 dan Core 1.

---

## ⚙️ Fungsi `xTaskCreatePinnedToCore()`

Fungsi ini merupakan bagian dari **FreeRTOS** yang digunakan untuk membuat *task baru* dan menentukan core mana yang akan menjalankannya.

```cpp
xTaskCreatePinnedToCore(
  function_name,  // Fungsi task
  task_name,      // Nama task
  stack_size,     // Ukuran stack
  task_parameter, // Parameter task
  priority,       // Prioritas
  task_handle,    // Handle task
  core_ID         // Core yang digunakan (0 atau 1)
);

