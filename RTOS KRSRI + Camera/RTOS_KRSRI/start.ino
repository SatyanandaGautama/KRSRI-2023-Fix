void start_coba() {
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
  //=============Rotate Start==============//
  //============Geser Kanan=================//

  readIRRange_4();
  while (IRRangeVal_4 < 12) {
    //    command("maju", 29, false);
    //    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_4();
    setGerakMaju();
    
  }

  sp_kompas = compassFront[0];
  readIRRange_6();
  while (IRRangeVal_6 < 47) {
    DEBUG_SERIAL.print("IR KIRI : ");
    DEBUG_SERIAL.println(IRRangeVal_6);
    navigasilurus(true, 4);
    command("geser_kanan", 16, false);
    vTaskDelay(15 / portTICK_PERIOD_MS);
    readIRRange_6();
  }
  //============Geser Kanan=================//
  //===========Kondisi Inverse===========//
  readIRRange_0();
  readIRRange_4();
  if (IRRangeVal_0 <= 15 && IRRangeVal_4 > 15) {
    deteksiK1Inverse();
  }
  //===========Kondisi Inverse==================//

  //============Kondisi Non Inverse==============//
  else {
    readIRRange_4();
    while (IRRangeVal_4 >= 12) {
      command("mundur", 6, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_4();
    }
    //============Turun Capit===============//
    vTaskDelay(300 / portTICK_PERIOD_MS); //200
    command("turun_capit", 11, true);
    command("kosong", 35, false);
    vTaskDelay(900 / portTICK_PERIOD_MS); //840
    //============Turun Capit===============//
    //==========Deteksi Korban 1 Non Inverse============//
    compassStart = compassFront[0];
    sp_kompas = compassFront[0];
    while (1) {
      Baca_kompas();
      vTaskDelay(20 / portTICK_PERIOD_MS);
      read_maix();
      vTaskDelay(20 / portTICK_PERIOD_MS);
      if (abs(compassOffset) >= 12 ) {
        if (compassOffset < 0) {
          command("rotateRightK1", 42, false);
          DEBUG_SERIAL.print("Offset kanan : ");
          DEBUG_SERIAL.println(compassOffset);
          vTaskDelay(35 / portTICK_PERIOD_MS);
        }
        else if (compassOffset > 0) {
          command("rotateLeftK1", 43, false);
          DEBUG_SERIAL.print("Offset kiri : ");
          DEBUG_SERIAL.println(compassOffset);
          vTaskDelay(35 / portTICK_PERIOD_MS);
        }
      }
      else if (pict_x < 172 - 7) {     //orang di sebelah kiri// non inverse arena = - 7
        navigasilurus(false, 4);
        command("geser_kiri_dikit", 8, false);
        vTaskDelay(25 / portTICK_PERIOD_MS);
        //      }
      }
      else if (pict_x > 172 + 9) {//orang di sebelah kanan// non inverse arena = + 9
        navigasilurus(true, 4);
        command("geser_kanan_dikit", 7, false);
        vTaskDelay(25 / portTICK_PERIOD_MS);
        //      }
      }
      else if (area < 8100) { //orang di tengah tapi jauh //7500
        //      navigasilurus(false, 2);
        command("maju_dikit", 5, false);
        vTaskDelay(40 / portTICK_PERIOD_MS);
      }
      else if (area > 7800  + 2100) { //7500 + 2200
        //      navigasilurus(true, 2);
        command("mundur_dikit", 6, false);
        vTaskDelay(40 / portTICK_PERIOD_MS);
      }
      else {
        command("grabK1", 10, true);
        vTaskDelay(20 / portTICK_PERIOD_MS);
        break;
      }
    }
  }
  //==========Deteksi Korban 1===========//
  command("kosong", 35, false);

  //============Rotate Korban 1=============//
  compassStart = compassFront[1];
  Baca_kompas();
  DEBUG_SERIAL.print("Arah : ");
  DEBUG_SERIAL.println(arah);
  DEBUG_SERIAL.print("Offset Awal: ");
  DEBUG_SERIAL.println(compassOffset);
  while (abs(compassOffset) >= 10) {
    if (compassOffset > 0) {
      command("rotateLeft", 19, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      DEBUG_SERIAL.print("Offset kiri : ");
      DEBUG_SERIAL.println(compassOffset);
    }
    else if (compassOffset < 0) {
      command("rotateRight", 18, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      DEBUG_SERIAL.print("Offset kanan : ");
      DEBUG_SERIAL.println(compassOffset);
    }
    Baca_kompas();
  }
  //============Rotate Korban 1=============//
  command("standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(30 / portTICK_PERIOD_MS);

  sp_kompas = compassFront[1] - 5;
  readIRRange_4();
  while (IRRangeVal_4 < 64) {
    navigasilurus(false, 4);
    command("maju", 21 , false);
    vTaskDelay(30 / portTICK_PERIOD_MS);
    readIRRange_4();
  }
  //============Jalan Pecah 1==============//
  while (pecah) {
    height = -82;
    height2 = -82;
    navigasilurus(false, 4);
    DEBUG_SERIAL.print("SP : ");
    DEBUG_SERIAL.println(sp_kompas);
    DEBUG_SERIAL.print("Arah : ");
    DEBUG_SERIAL.println(arah);
    readPitch();
    if (pitch < -8) {
      pecah = false;
    }
    else {
      command("jalan_pecah", 4, false);
      vTaskDelay(30 / portTICK_PERIOD_MS);
    }
  }
  //============Jalan Pecah 1==============//
  //===============Turunan================//
  command("Standby", 99, true);
  command("kosong", 35, false);
  vTaskDelay(300 / portTICK_PERIOD_MS);
  command("TransisiTurunan", 20, true);
  command("kosong", 35, false);
  vTaskDelay(200 / portTICK_PERIOD_MS);

  readIRRange_6();
  while (IRRangeVal_6 < 50) {
    height = -95;
    height2 = -75;
    if (IRRangeVal_2 > 50) {
      break;
    }
    else {
      navigasilurus(false, 4);
      command("maju_turunan1", 1, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
    }
    readIRRange_6();
    readIRRange_2();
    DEBUG_SERIAL.print("IR KIRI : ");
    DEBUG_SERIAL.println(IRRangeVal_6);
    DEBUG_SERIAL.print("IR KANAN : ");
    DEBUG_SERIAL.println(IRRangeVal_2);
  }
  //===============Turunan================//
  sp_kompas = compassFront[1] - 5;
  readIRRange_0();
  while (IRRangeVal_0 >= 27) {
    navigasilurus(false, 4);
    command("maju_turunan2", 21, false);
    vTaskDelay(40 / portTICK_PERIOD_MS);
    readIRRange_0();
    DEBUG_SERIAL.print("IR DEPAN : ");
    DEBUG_SERIAL.println(IRRangeVal_0);
  }
  //===============Turunan================//

  //=============================================================//
  //=================Kondisi INVERSE============================//
  //===========================================================//
  readIRRange_2();
  //======Taruh Korban 1 Inverse Arena===========//
  if (IRRangeVal_2 > 40) {
    deteksiK2Inverse();
  }

  //=============================================================//
  //================Kondisi Non INVERSE=========================//
  //===========================================================//
  else {
    //======Taruh Korban 1 Non Inverse Arena===========//
    sp_kompas = compassFront[1] - 5;
    readIRRange_2();
    while (IRRangeVal_2 >= 8) {
      navigasilurus(true, 4);
      command("kananbatu", 26, false);
      vTaskDelay(40 / portTICK_PERIOD_MS);
      readIRRange_2();
      DEBUG_SERIAL.print("IR KANAN : ");
      DEBUG_SERIAL.println(IRRangeVal_2);
    }
    readIRRange_2();
    while (IRRangeVal_2 <= 14) {
      navigasilurus(false, 4);
      command("kiribatu", 27, false);
      vTaskDelay(50 / portTICK_PERIOD_MS);
      readIRRange_2();
      DEBUG_SERIAL.print("IR KANAN : ");
      DEBUG_SERIAL.println(IRRangeVal_2);
    }

    compassStart = 136;
    Baca_kompas();
    DEBUG_SERIAL.println("TARUHK1 NON");
    DEBUG_SERIAL.print("Arah : ");
    DEBUG_SERIAL.println(arah);
    while (abs(compassOffset) >= 8) {
      if (compassOffset < 0) {
        command("rotateRightStart", 14, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      else if (compassOffset > 0) {
        command("rotateLeftStart", 15, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      Baca_kompas();
    }

    command("taruhK1NonInverse", 25, true);
    command("kosong", 35, false);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    compassStart = 96;
    Baca_kompas();
    while (abs(compassOffset) >= 10) {
      if (compassOffset < 0) {
        command("rotateRightStart", 14, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      else if (compassOffset > 0) {
        command("rotateLeftStart", 15, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      Baca_kompas();
    }
    //======Taruh Korban 1 Inverse Arena===========//
    //======Taruh Korban 1 Non Inverse Arena===========//
    //=============Menuju Korban 2 Non Inverse Arena===========//
    sp_kompas = compassFront[1] - 8;
    readIRRange_2();
    while (IRRangeVal_2 < 22) {
      navigasilurus(false, 4);
      command("kiribatu", 27, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_2();
      DEBUG_SERIAL.print("IR KANAN : ");
      DEBUG_SERIAL.println(IRRangeVal_2);
    }
    readIRRange_0();
    while (IRRangeVal_0 >= 11) {
      for (int i = 0; i <= 3; i++) {
        navigasilurus(false, 4);
        command("majuserong", 21, true);
      }
      command("kosong", 35, false);
      vTaskDelay(30 / portTICK_PERIOD_MS); //30
      for (int i = 0; i <= 2; i++) {
        navigasilurus(false, 4);
        command("kiriserong", 27, true);
      }
      command("kosong", 35, false);
      vTaskDelay(30 / portTICK_PERIOD_MS); //30
      readIRRange_0();
    }
    readIRRange_2();
    readIRRange_6();
    while (IRRangeVal_2 <= 58 && IRRangeVal_6 >= 44) {
      pict_x = 200;
      area = 0;
      navigasilurus(false, 4);
      command("kiribatu", 27, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_2();
      readIRRange_6();
    }
    //=============Menuju Korban 2 Non Inverse Arena===========//
    //=============Rotate Korban 2==========//

    compassStart = 255;
    Baca_kompas();
    DEBUG_SERIAL.println("DETEKSI K2");
    DEBUG_SERIAL.print("Arah : ");
    DEBUG_SERIAL.println(arah);
    while (abs(compassOffset) >= 8) {
      DEBUG_SERIAL.println("while rotate K2");
      if (compassOffset < 0) {
        command("rotRightBatu", 47, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kanan : ");
        DEBUG_SERIAL.println(compassOffset);
      }
      else if (compassOffset > 0) {
        command("rotLeftBatu", 48, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kiri : ");
        DEBUG_SERIAL.println(compassOffset);
      }
      Baca_kompas();
    }
    readIRRange_4();
    while (IRRangeVal_4 <= 11) {
      DEBUG_SERIAL.println("while baca belakang");
      command("maju", 29, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_4();
    }

    vTaskDelay(300 / portTICK_PERIOD_MS);
    command("turun_capit", 11, true);
    command("kosong", 35, false);
    vTaskDelay(1100 / portTICK_PERIOD_MS);
    //=============Rotate Korban 2==========//
    //=============Deteksi Korban 2=========//
    pict_x = 200;
    area = 0;
    Baca_kompas();
    DEBUG_SERIAL.println("DETEKSI K2");
    DEBUG_SERIAL.print("Arah : ");
    DEBUG_SERIAL.println(arah);
    compassStart = 255;
    while (1) {
      DEBUG_SERIAL.println("while K2");
      Baca_kompas();
      vTaskDelay(30 / portTICK_PERIOD_MS);
      read_maix();
      vTaskDelay(50 / portTICK_PERIOD_MS);
      if (abs(compassOffset) >= 15 ) {
        if (compassOffset < 0) {
          command("rotateRightKelereng", 36, false);
          vTaskDelay(30 / portTICK_PERIOD_MS);
        }
        else if (compassOffset > 0) {
          command("rotateLeftKelereng", 37, false);
          vTaskDelay(30 / portTICK_PERIOD_MS);
        }
      }
      else if (pict_x < 160 - 14) {     //orang di sebelah kiri
        command("geser_kiri_dikit", 32, false);
        vTaskDelay(30 / portTICK_PERIOD_MS);
      }
      else if (pict_x > 160 + 10) {//orang di sebelah kanan
        command("geser_kanan_dikit", 31, false);
        vTaskDelay(30 / portTICK_PERIOD_MS);
      }
      else if (area < 10000) { //orang di tengah tapi jauh
        command("maju_dikit", 29, false);
        vTaskDelay(40 / portTICK_PERIOD_MS);

      }//kalo mau tambahin pke area bisa buat else if baru
      else if (area > 10000 + 3000) { //1700
        command("mundur_dikit", 30, false);
        vTaskDelay(40 / portTICK_PERIOD_MS);
      }
      else {
        command("grabK2", 23, true);
        vTaskDelay(10 / portTICK_PERIOD_MS);
        break;
      }
    }
    //=============Deteksi Korban 2=========//
    command("kosong", 35, false);
    //=============Rotate Korban 2=========//
    compassStart = compassFront[0] + 2;
    Baca_kompas();
    DEBUG_SERIAL.print("Arah : ");
    DEBUG_SERIAL.println(arah);
    DEBUG_SERIAL.print("Offset Awal: ");
    DEBUG_SERIAL.println(compassOffset);
    while (abs(compassOffset) >= 10) {
      DEBUG_SERIAL.println("while rotate K2");
      if (compassOffset < 0) {
        command("rotRightBatu", 14, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kanan : ");
        DEBUG_SERIAL.println(compassOffset);
      }
      else if (compassOffset > 0) {
        command("rotLeftBatu", 15, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
        DEBUG_SERIAL.print("Offset kiri : ");
        DEBUG_SERIAL.println(compassOffset);
      }
      Baca_kompas();
    }
    //=============Rotate Korban 2=========//
    //=============Safety Zone 2===========//
    sp_kompas = compassFront[0] + 10;
    while (1) {
      readIRRange_2();
      readIRRange_0();
      readIRRange_4();
      if (IRRangeVal_2 >= 10) {
        navigasilurus(true, 4);
        command("kananbatu", 26, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      else if (IRRangeVal_0 > 27 && IRRangeVal_4 < 76) {
        navigasilurus(false, 4);
        command("majubatu", 21, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      else {
        vTaskDelay(100 / portTICK_PERIOD_MS);
        command("taruhkorban", 25, true);
        break;
      }
    }
    //====================================//
    command("kosong", 35, false);
    vTaskDelay(300 / portTICK_PERIOD_MS);
    //===================================//
    //=============Safety Zone 2===========//
    //////////Menuju Tangga atau Korban 3/4////////////////////
    compassStart = compassFront[3];
    Baca_kompas();
    while (abs(compassOffset) >= 10) {
      if (compassOffset < 0) {
        command("rotRightBatu", 47, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      else if (compassOffset > 0) {
        command("rotLeftBatu", 48, false);
        vTaskDelay(15 / portTICK_PERIOD_MS);
      }
      Baca_kompas();
    }
    sp_kompas = compassFront[3];
    readIRRange_4();
    while (IRRangeVal_4 <= 19) {
      navigasilurus(false, 4);
      command("majubatu", 21, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_4();
    }
    readIRRange_2();
    while (IRRangeVal_2 >= 15) {
      navigasilurus(true, 4);
      command("geserkanan", 26, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_2();
    }

    readIRRange_4();
    while (IRRangeVal_4 <= 70) {
      navigasilurus(false, 4);
      command("maju", 21, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_4();
    }

    Baca_kompas();
    DEBUG_SERIAL.println("KIRI PECAH 2");
    DEBUG_SERIAL.print("Arah : ");
    DEBUG_SERIAL.println(arah);
    sp_kompas = compassFront[3];
    readIRRange_6();
    while (IRRangeVal_6 >= 6) {
      navigasilurus(false, 3.5);
      command("kiricepat", 55, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_6();
    }

    height = -88;
    height2 = -88;
    command("standby", 99, true);
    command("kosong", 35, false);
    vTaskDelay(300 / portTICK_PERIOD_MS);

    compassStart = compassFront[3];
    Baca_kompas();
    while (abs(compassOffset) >= 14 ) {
      height = -88;
      height2 = -88;
      if (compassOffset < 0) {
        command("rotateRightPecah", 39, false);
      }
      else if (compassOffset > 0) {
        command("rotateLeftPecah", 40, false);
      }
      Baca_kompas();
    }
    //////////////////////////////////////Deteksi Korban 4////////////////////////////////
    DEBUG_SERIAL.print(F("PECAH 2"));
    readIRRange_0();
    readIRRange_4();
    DEBUG_SERIAL.print(F("IR DEPAN: "));
    DEBUG_SERIAL.print(IRRangeVal_0);
    DEBUG_SERIAL.print(F("IR BELAKANG: "));
    DEBUG_SERIAL.print(IRRangeVal_4);
    sp_kompas = compassFront[3];
    height = -88;
    height2 = -88;
    while (IRRangeVal_0 > 19 && IRRangeVal_4 < 102) {  //IRRangeVal_0 > 18 && IRRangeVal_4 < 102
      navigasilurus(false, 4);
      command("majupecah", 4, false);
      vTaskDelay(10 / portTICK_PERIOD_MS);
      readIRRange_0();
      readIRRange_4();
    }
    compassStart = compassFront[3];
    readIRRange_2();
    readIRRange_6();
    while (IRRangeVal_2 > 12 && IRRangeVal_6 < 49 ) {
      navigasilurus(true, 4);
      command("kananbatu", 26, false);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      readIRRange_2();
      readIRRange_6();
    }
    //=============Gerakan Naik Tangga===============//
    readPitch();
    while (pitch <= 12) { //11
      compassStart = compassFront[3] - 20;
      Baca_kompas();
      if (abs(compassOffset) >= 20) {
        if (compassOffset < 0) {
          command("rotRightBatu", 47, false);
          vTaskDelay(15 / portTICK_PERIOD_MS);
          DEBUG_SERIAL.print("Offset kanan : ");
          DEBUG_SERIAL.println(compassOffset);
        }
        else if (compassOffset > 0) {
          command("rotLeftBatu", 48, false);
          vTaskDelay(15 / portTICK_PERIOD_MS);
          DEBUG_SERIAL.print("Offset kiri : ");
          DEBUG_SERIAL.println(compassOffset);
        }
      }
      else {
        height = -85;
        height2 = -85;
        command("TransisiTangga1", 44, false);
        readPitch();
      }
    }

    command("Standby", 57, true);
    command("kosong", 35, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    command("StandbyTransisi1", 49, true);
    command("kosong", 35, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);

    while (tangga) {
      height = -85;
      height2 = -90;
      readPitch();
      if (pitch > 28) {
        tangga = false;
      }
      else {
        command("NaikTangga", 45, false);
        vTaskDelay(10 / portTICK_PERIOD_MS);
      }
    }

    command("StandbyTransisi2", 50, true);
    command("kosong", 35, false);
    vTaskDelay(50 / portTICK_PERIOD_MS);

    while (1) {
      height = -85;
      height2 = -90;
      command("NaikTanggaFix", 58, false);
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }
}
//=============Gerakan Naik Tangga===============//
