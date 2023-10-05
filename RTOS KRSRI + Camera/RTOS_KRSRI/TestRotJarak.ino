void RotJarakKiri() {
  SpJarak = 0;
  readIRRange_0();
  readIRRange_4();
  JarakNow = IRRangeVal_0 - (IRRangeVal_4 - 2);
  OffsetJarak = abs(SpJarak - abs(JarakNow));
  SudutRotate = map(OffsetJarak, 1, 20, 8, 40);
}
void TestRotJarak() {
  while (ButtonState == 1) {
    ButtonState = digitalRead(Button);
    display.clearDisplay();             // mengosongkan tampilan
    Baca_kompas();
    display.display();                  // menampilkan karakter yang sudah disimpan
    display.drawPixel(0, 0, WHITE);
    display.drawPixel(127, 0, WHITE);
    display.drawPixel(0, 31, WHITE);
    display.drawPixel(127, 31, WHITE);

    display.setTextSize(1);             // set ukuran huruf
    display.setTextColor(WHITE);        // set warna huruf
    display.setCursor(33, 6);
    display.print("CMPS HEADING");

    display.setTextSize(2);             // set ukuran huruf
    display.setTextColor(WHITE);        // set warna huruf
    display.setCursor(50, 16);
    display.print(arah);
    display.print(" ");
    display.setTextSize(1);
    display.cp437(true);
    display.write(167);
    display.display();                  // menampilkan karakter yang sudah disimpan

    if (ButtonState == 0) {
      calKompas = heading;
      Baca_kompas();
      display.clearDisplay();           // mengosongkan tampilan
      while (abs(compassOffset) >= 7) {
        if (compassOffset < 0) {
          command("rotateRightStart", 18, false);
          vTaskDelay(15 / portTICK_PERIOD_MS);
        }
        else if (compassOffset > 0) {
          command("rotateLeftStart", 19, false);
          vTaskDelay(15 / portTICK_PERIOD_MS);
        }
        Baca_kompas();
      }
    }
    vTaskDelay(15 / portTICK_PERIOD_MS);
  }

  RotJarakKiri();
  vTaskDelay(50 / portTICK_PERIOD_MS);
  while (OffsetJarak > 1) {
    if (JarakNow < 0) {
      command("rotateKanan", 14, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    else if (JarakNow > 0) {
      command("rotateKiri", 15, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    RotJarakKiri();
  }
  readIRRange_2();
  while (IRRangeVal_2 < 100) {
    //    susurkiriV2(10);
    //    command("maju", 66, false);
    //    vTaskDelay(30 / portTICK_PERIOD_MS);
    //        readIRRange_2();
    susurkiriV3(3);
    command("maju_batu", 21, false);
    vTaskDelay(30 / portTICK_PERIOD_MS);
    readIRRange_2();
  }

  RotJarakKiri();
  while (OffsetJarak > 1) {
    if (JarakNow < 0) {
      command("rotateKanan", 14, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    else if (JarakNow > 0) {
      command("rotateKiri", 15, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    RotJarakKiri();
  }
  Baca_kompas();
  calKompas = heading;

  command("Standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  command("Yaw20", 67, true);
  command("kosong", 35, false);
  vTaskDelay(300 / portTICK_PERIOD_MS);
  command("Standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  command("Yaw_20", 68, true);
  command("kosong", 35, false);
  vTaskDelay(300 / portTICK_PERIOD_MS);
  command("Standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(200 / portTICK_PERIOD_MS);

  for (int i = 0; i <= 2; i++) {
    command("Pitch20", 71, true);
    command("kosong", 35, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    command("Pitch_20", 72, true);
    command("kosong", 35, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }

  command("Standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(300 / portTICK_PERIOD_MS); //200
  command("turun_capit", 11, true);
  command("kosong", 35, false);
  vTaskDelay(500 / portTICK_PERIOD_MS); //840

  //=====Deteksi Korban====//
  while (1) {
    ReadPING_1();
    if (jarak[0] > 12) {
      command("maju_dikit", 5, false);
      vTaskDelay(20 / portTICK_PERIOD_MS);
    }
    else {
      command("grabK1", 10, true);
      vTaskDelay(20 / portTICK_PERIOD_MS);
      break;
    }
  }
  command("kosong", 35, false);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  //=====Deteksi Korban====//

  compassStart = 180;
  Baca_kompas();
  while (abs(compassOffset) >= 8) {
    if (compassOffset < 0) {
      command("rotateRightStart", 18, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else if (compassOffset > 0) {
      command("rotateLeftStart", 19, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    Baca_kompas();
  }

  RotJarakKiri();
  while (OffsetJarak > 0) {
    if (JarakNow < 0) {
      command("rotateKanan", 14, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    else if (JarakNow > 0) {
      command("rotateKiri", 15, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    RotJarakKiri();
  }
  Baca_kompas();
  calKompas = heading;

  readIRRange_2();
  while (IRRangeVal_2 < 75) {
    //    susurkiriV2(10);
    //    command("maju", 66, false);
    //    vTaskDelay(30 / portTICK_PERIOD_MS);
    //        readIRRange_2();
    susurkiriV3(3);
    command("maju_batu", 21, false);
    vTaskDelay(30 / portTICK_PERIOD_MS);
    readIRRange_2();
  }

  RotJarakKiri();
  while (OffsetJarak > 1) {
    if (JarakNow < 0) {
      command("rotateKanan", 14, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    else if (JarakNow > 0) {
      command("rotateKiri", 15, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    RotJarakKiri();
  }

  //===Taruh Korban===//
  vTaskDelay(100 / portTICK_PERIOD_MS);
  command("taruhkorban", 25, true);
  command("kosong", 35, false);
  vTaskDelay(200 / portTICK_PERIOD_MS);

  compassStart = 180;
  Baca_kompas();
  while (abs(compassOffset) >= 8) {
    if (compassOffset < 0) {
      command("rotateRightStart", 18, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    else if (compassOffset > 0) {
      command("rotateLeftStart", 19, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    Baca_kompas();
  }

  RotJarakKiri();
  while (OffsetJarak > 0) {
    if (JarakNow < 0) {
      command("rotateKanan", 14, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    else if (JarakNow > 0) {
      command("rotateKiri", 15, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
    }
    RotJarakKiri();
  }
  Baca_kompas();
  calKompas = heading;

  command("Standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(100 / portTICK_PERIOD_MS);

  for (int i = 0; i <= 2; i++) {
    command("Pitch20", 71, true);
    command("kosong", 35, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    command("Pitch_20", 72, true);
    command("kosong", 35, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }

  while (1) {
    command("Inhale", 69, true);
    command("kosong", 35, false);
    vTaskDelay(200 / portTICK_PERIOD_MS);
    command("Exhale", 70, true);
    command("kosong", 35, false);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}
