void ambilK1Fx() {
  float deg1 = 225; //205
  float deg2 = 160; //190
  float xFront = 53;
  float yFront = 57;
  float xBack = 58;
  for (int i = 0; i <= 49; i++) {
    FR(xFront, yFront, 0, 0);
    BR(xBack, -55, 0, 0);
    BL3(-(xBack), -55, 0, 0);
    FL(-(xFront), yFront, 0, 0);
    dxl.setGoalPosition(14, deg1, UNIT_DEGREE);
    dxl.setGoalPosition(15, deg2, UNIT_DEGREE);
    deg1 -= 0.4;
    deg2 += 0.6;
    xFront -= 1.0252; //tujuan = 1.74
    yFront += 0.9282; //tujuan = 103.41
    xBack += 1.14; // tujuan = 115
    delay(15);
  }
}
void majubatu1(float lbr) { //Gerakan lambat naik 3.5 cm
  arahgerak = true;
  height = -75;
  height2 = -75;
  movecounter++;
  if (movecounter == 1) {
    FR(55, 55, 35, lbr);
    BL(-55, -55, 35, lbr);
    FL(-55, 55, 0, lbr);
    BR(55, -55, 0, lbr);
    delay(tbk);

    FR(69.44, 55, 31.11, lbr);
    BL(-40.56, -55, 31.11, lbr);
    FL(-52.11, 55, 0, lbr);
    BR(57.89, -55, 0, lbr);
    delay(tbk);

    FR(80.56, 55, 19.44, lbr);
    BL(-29.44, -55, 19.44, lbr);
    FL(-49.89, 55, 0, lbr);
    BR(60.11, -55, 0, lbr);
    delay(tbk);
    ////////////////////////////////////////////////////////
    FR(85.00, 55.00, 0.00, lbr);
    BL(-25.00, -55.00, 0.00, lbr);
    FL(-49.00, 55.00, 0.00, lbr);
    BR(61.00, -55.00, 0.00, lbr);
    delay(tbk);


    FR(84.53, 55.00, 0.00, lbr);
    BL(-25.47, -55.00, 0.00, lbr);
    FL(-48.53, 55.00, 0.00, lbr);
    BR(61.47, -55.00, 0.00, lbr);
    delay(tbk);


    FR(83.22, 55.00, 0.00, lbr);
    BL(-26.78, -55.00, 0.00, lbr);
    FL(-47.22, 55.00, 0.00, lbr);
    BR(62.78, -55.00, 0.00, lbr);
    delay(tbk);


    FR(81.25, 55.00, 0.00, lbr);
    BL(-28.75, -55.00, 0.00, lbr);
    FL(-45.25, 55.00, 0.00, lbr);
    BR(64.75, -55.00, 0.00, lbr);
    delay(tbk);


    FR(78.78, 55.00, 0.00, lbr);
    BL(-31.22, -55.00, 0.00, lbr);
    FL(-42.78, 55.00, 0.00, lbr);
    BR(67.22, -55.00, 0.00, lbr);
    delay(tbk);


    FR(75.97, 55.00, 0.00, lbr);
    BL(-34.03, -55.00, 0.00, lbr);
    FL(-39.97, 55.00, 0.00, lbr);
    BR(70.03, -55.00, 0.00, lbr);
    delay(tbk);


    FR(73.00, 55.00, 0.00, lbr);
    BL(-37.00, -55.00, 0.00, lbr);
    FL(-37.00, 55.00, 0.00, lbr);
    BR(73.00, -55.00, 0.00, lbr);
    delay(tbk);


    FR(70.03, 55.00, 0.00, lbr);
    BL(-39.97, -55.00, 0.00, lbr);
    FL(-34.03, 55.00, 0.00, lbr);
    BR(75.97, -55.00, 0.00, lbr);
    delay(tbk);


    FR(67.22, 55.00, 0.00, lbr);
    BL(-42.78, -55.00, 0.00, lbr);
    FL(-31.22, 55.00, 0.00, lbr);
    BR(78.78, -55.00, 0.00, lbr);
    delay(tbk);


    FR(64.75, 55.00, 0.00, lbr);
    BL(-45.25, -55.00, 0.00, lbr);
    FL(-28.75, 55.00, 0.00, lbr);
    BR(81.25, -55.00, 0.00, lbr);
    delay(tbk);


    FR(62.78, 55.00, 0.00, lbr);
    BL(-47.22, -55.00, 0.00, lbr);
    FL(-26.78, 55.00, 0.00, lbr);
    BR(83.22, -55.00, 0.00, lbr);
    delay(tbk);


    FR(61.47, 55.00, 0.00, lbr);
    BL(-48.53, -55.00, 0.00, lbr);
    FL(-25.47, 55.00, 0.00, lbr);
    BR(84.53, -55.00, 0.00, lbr);
    delay(tbk);


    FR(61.00, 55.00, 0.00, lbr);
    BL(-49.00, -55.00, 0.00, lbr);
    FL(-25.00, 55.00, 0.00, lbr);
    BR(85.00, -55.00, 0.00, lbr);
    delay(tbk);
    /////////////////////////////////////////////
    FR(60.11, 55, 0, lbr);
    BL(-49.89, -55, 0, lbr);
    FL(-29.44, 55, 19.44, lbr);
    BR(80.56, -55, 19.44, lbr);
    delay(tbk);

    FR(57.89, 55, 0, lbr);
    BL(-52.11, -55, 0, lbr);
    FL(-40.56, 55, 31.11, lbr);
    BR(69.44, -55, 31.11, lbr);
    delay(tbk);
  }
  else if (movecounter == 2) {
    FR(55, 55, 0, lbr);
    BL(-55, -55, 0, lbr);
    FL(-55, 55, 35, lbr);
    BR(55, -55, 35, lbr);
    delay(tbk);

    FR(52.11, 55, 0, lbr);
    BL(-57.89, -55, 0, lbr);
    FL(-69.44, 55, 31.11, lbr);
    BR(40.56, -55, 31.11, lbr);
    delay(tbk);

    FR(49.89, 55, 0, lbr);
    BL(-60.11, -55, 0, lbr);
    FL(-80.56, 55, 19.44, lbr);
    BR(29.44, -55, 19.44, lbr);
    delay(tbk);
    //////////////////////////////////////////////
    FR(49.00, 55.00, 0.00, lbr);
    BL(-61.00, -55.00, 0.00, lbr);
    FL(-85.00, 55.00, 0.00, lbr);
    BR(25.00, -55.00, 0.00, lbr);
    delay(tbk);


    FR(48.53, 55.00, 0.00, lbr);
    BL(-61.47, -55.00, 0.00, lbr);
    FL(-84.53, 55.00, 0.00, lbr);
    BR(25.47, -55.00, 0.00, lbr);
    delay(tbk);


    FR(47.22, 55.00, 0.00, lbr);
    BL(-62.78, -55.00, 0.00, lbr);
    FL(-83.22, 55.00, 0.00, lbr);
    BR(26.78, -55.00, 0.00, lbr);
    delay(tbk);


    FR(45.25, 55.00, 0.00, lbr);
    BL(-64.75, -55.00, 0.00, lbr);
    FL(-81.25, 55.00, 0.00, lbr);
    BR(28.75, -55.00, 0.00, lbr);
    delay(tbk);


    FR(42.78, 55.00, 0.00, lbr);
    BL(-67.22, -55.00, 0.00, lbr);
    FL(-78.78, 55.00, 0.00, lbr);
    BR(31.22, -55.00, 0.00, lbr);
    delay(tbk);


    FR(39.97, 55.00, 0.00, lbr);
    BL(-70.03, -55.00, 0.00, lbr);
    FL(-75.97, 55.00, 0.00, lbr);
    BR(34.03, -55.00, 0.00, lbr);
    delay(tbk);


    FR(37.00, 55.00, 0.00, lbr);
    BL(-73.00, -55.00, 0.00, lbr);
    FL(-73.00, 55.00, 0.00, lbr);
    BR(37.00, -55.00, 0.00, lbr);
    delay(tbk);


    FR(34.03, 55.00, 0.00, lbr);
    BL(-75.97, -55.00, 0.00, lbr);
    FL(-70.03, 55.00, 0.00, lbr);
    BR(39.97, -55.00, 0.00, lbr);
    delay(tbk);


    FR(31.22, 55.00, 0.00, lbr);
    BL(-78.78, -55.00, 0.00, lbr);
    FL(-67.22, 55.00, 0.00, lbr);
    BR(42.78, -55.00, 0.00, lbr);
    delay(tbk);


    FR(28.75, 55.00, 0.00, lbr);
    BL(-81.25, -55.00, 0.00, lbr);
    FL(-64.75, 55.00, 0.00, lbr);
    BR(45.25, -55.00, 0.00, lbr);
    delay(tbk);


    FR(26.78, 55.00, 0.00, lbr);
    BL(-83.22, -55.00, 0.00, lbr);
    FL(-62.78, 55.00, 0.00, lbr);
    BR(47.22, -55.00, 0.00, lbr);
    delay(tbk);


    FR(25.47, 55.00, 0.00, lbr);
    BL(-84.53, -55.00, 0.00, lbr);
    FL(-61.47, 55.00, 0.00, lbr);
    BR(48.53, -55.00, 0.00, lbr);
    delay(tbk);


    FR(25.00, 55.00, 0.00, lbr);
    BL(-85.00, -55.00, 0.00, lbr);
    FL(-61.00, 55.00, 0.00, lbr);
    BR(49.00, -55.00, 0.00, lbr);
    delay(tbk);
    /////////////////////////////////////////////
    FR(29.44, 55, 19.44, lbr);
    BL(-80.56, -55, 19.44, lbr);
    FL(-60.11, 55, 0, lbr);
    BR(49.89, -55, 0, lbr);
    delay(tbk);

    FR(40.56, 55, 31.11, lbr);
    BL(-69.44, -55, 31.11, lbr);
    FL(-57.89, 55, 0, lbr);
    BR(52.11, -55, 0, lbr);
    delay(tbk);
    movecounter = 0;
  }
}

void taruhkorban() {
  standby();
  float deg5 = 57; //57 to 205
  for (int i = 0; i <= 19; i++) {
    dxl.setGoalPosition(14, deg5, UNIT_DEGREE);
    deg5 += 7.4;
    delay(25);
  }
  delay(700);
  capit.write(170);
  delay(700);

  float deg7 = 205; //to 225
  float deg9 = 70; // to 35
  for (int i = 0; i <= 39; i++) {
    dxl.setGoalPosition(14, deg7, UNIT_DEGREE);
    pegangan.write(deg9);
    deg7 += 0.5;
    deg9 -= 0.875;
    delay(10);
  }
  float deg6 = 35; //to 45
  float deg8 = 225; //to 57
  for (int i = 0; i <= 19; i++) {
    dxl.setGoalPosition(14, deg8, UNIT_DEGREE);
    pegangan.write(deg6);
    deg8 -= 7.4;
    deg6 -= 0.5;
    delay(25);
  }
  delay(500);
  capit.write(156);
}

void ambilK1() {
  //  pict_x = 0;
  //  area = 0;
  float deg1 = 225; //205
  float deg2 = 35; //70
  float xFront = 53;
  float yFront = 57;
  float xBack = 58;
  for (int i = 0; i <= 49; i++) {
    FR(xFront, yFront, 0, 0);
    BR(xBack, -55, 0, 0);
    BL3(-(xBack), -55, 0, 0);
    FL(-(xFront), yFront, 0, 0);
    dxl.setGoalPosition(14, deg1, UNIT_DEGREE);
    pegangan.write(deg2);
    deg1 -= 0.4;
    deg2 += 0.7;
    xFront -= 1, 0252; //tujuan = 1.74
    yFront += 0.9282; //tujuan = 103.41
    xBack += 1.14; // tujuan = 115
    delay(10);
  }
}

void ambilKorban2() {
  standby();
  float deg1 = 225; //205 //200 new
  float deg2 = 35; //75
  float xFront = 53;
  float yFront = 57;
  float xBack = 58;
  for (int i = 0; i <= 19; i++) {
    FR2(xFront, yFront, 0, 0);
    BR2(xBack, -55, 0, 0);
    BL2(-(xBack), -55, 0, 0);
    FL2(-(xFront), yFront, 0, 0);
    dxl.setGoalPosition(14, deg1, UNIT_DEGREE);
    pegangan.write(deg2);
    deg1 -= 1.25;
    deg2 += 2;
    xFront -= 2.563; //tujuan = 1.74
    yFront += 2.3205; //tujuan = 103.41
    xBack += 2.85; // tujuan = 115
    delay(25);
  }
}

void ambilkorban() {
  FR(45, 73.41, 0, 0);
  BR(67.5, -55, 0, 0);
  BL(-67.5, -55, 0, 0);
  FL(-45, 73.41, 0, 0);
  delay(td2);
  FR(35, 73.41, 0, 0);
  BR(77.5, -55, 0, 0);
  BL(-77.5, -55, 0, 0);
  FL(-35, 73.41, 0, 0);
  delay(td2);
  FR(25, 83.41, 0, 0);
  BR(90, -55, 0, 0);
  BL(-90, -55, 0, 0);
  FL(-25, 83.41, 0, 0);
  delay(td2);
  FR(15, 93.41, 0, 0);
  BR(102.5, -55, 0, 0);
  BL(-102.5, -55, 0, 0);
  FL(-15, 93.41, 0, 0);
  delay(td2);

  FR(1.74, 103.41, 0, 0);
  BR(115, -55, 0, 0);
  BL(-115, -55, 0, 0);
  FL(-1.74, 103.41, 0, 0);
  delay(td2);
  FR(1.74, 103.41, 0, 0);
  BR(115, -55, 0, 0);
  BL(-115, -55, 0, 0);
  FL(-1.74, 103.41, 0, 0);
  delay(td2);
  FR(1.74, 103.41, 0, 0);
  BR(115, -55, 0, 0);
  BL(-115, -55, 0, 0);
  FL(-1.74, 103.41, 0, 0);
  delay(td2);
  //FR(15,93.41,0,0);
  //BR(102.5,-55,0,0);
  //BL(-102.5,-55,0,0);
  //FL(-15,93.41,0,0);
  //delay(td2);
  //FR(25,83.41,0,0);
  //BR(90,-55,0,0);
  //BL(-90,-55,0,0);
  //FL(-25,83.41,0,0);
  //delay(td2);
  //FR(35,73.41,0,0);
  //BR(77.5,-55,0,0);
  //BL(-77.5,-55,0,0);
  //FL(-35,73.41,0,0);
  //delay(td2);
  //FR(45,73.41,0,0);
  //BR(67.5,-55,0,0);
  //BL(-67.5,-55,0,0);
  //FL(-45,73.41,0,0);
  //delay(td2);
}

//Capit Turun 235, naik 65
//void turuncapit() {
//  for (int i = 65; i <= 225; i++) {
//    dxl.setGoalPosition(14, i, UNIT_DEGREE);
//    delay(3);
//  }
//}
//
//void naikcapit() {
//  for (int i = 205; i >= 65; i--) {
//    dxl.setGoalPosition(14, i, UNIT_DEGREE);
//    delay(3);
//  }
//}
//
//void ambil(){
//int deg1 = 225; //205
//float deg2 = 35; //70
//float xFront = 53;
//float yFront = 57;
//float xBack = 58;
//    for (int i = 0; i <= 20; i++) {
//    FR(xFront, yFront, 0, 0);
//    BR(xBack, -55, 0, 0);
//    BL(-(xBack), -55, 0, 0);
//    FL(-(xFront), yFront, 0, 0);
//    dxl.setGoalPosition(14, deg1, UNIT_DEGREE);
//    pegangan.write(deg2);
//    deg1 -=1;
//    deg2 +=1.75;
//    xFront -= 2.563; //tujuan = 1.74
//    yFront += 2.3205; //tujuan = 103.41
//    xBack += 2.85; // tujuan = 115
//    delay(5);
//  }
//}
//
//void balik(){
//float xFront = 1.74;
//float yFront = 103.41;
//float xBack = 115;
//    for (int i = 0; i <= 20; i++) {
//    FR(xFront, yFront, 0, 0);
//    BR(xBack, -55, 0, 0);
//    BL(-(xBack), -55, 0, 0);
//    FL(-(xFront), yFront, 0, 0);
//    xFront += 2.563; //tujuan = 1.74
//    yFront -= 2.3205; //tujuan = 103.41
//    xBack -= 2.85; // tujuan = 115
//    delay(5);
//  }
//}
//
//void nyapit(){
//  capit.write(115);
//  pegangan.write(35);
//}

void turuncapit() {
  standby();
  float degX = 63; // to 225
  float degY = 165; // to 160
  digitalWrite(PB9, HIGH);
  for (int i = 0; i <= 39; i++) {
    dxl.setGoalPosition(14, degX, UNIT_DEGREE);
    dxl.setGoalPosition(15, degY, UNIT_DEGREE);
    degX += 4.05;
    degY -= 0.125;
    delay(20);
  }
}

void ambilK1Fix() {
  //  pict_x = 0;
  //  area = 0;
  float deg1 = 225; //205
  float deg2 = 35; //70
  float xFront = 53;
  float yFront = 57;
  float xBack = 58;
  for (int i = 0; i <= 49; i++) {
    FR(xFront, yFront, 0, 0);
    BR(xBack, -55, 0, 0);
    BL3(-(xBack), -55, 0, 0);
    FL(-(xFront), yFront, 0, 0);
    dxl.setGoalPosition(14, deg1, UNIT_DEGREE);
    pegangan.write(deg2);
    deg1 -= 0.4;
    deg2 += 0.7;
    xFront -= 1, 0252; //tujuan = 1.74
    yFront += 0.9282; //tujuan = 103.41
    xBack += 1.14; // tujuan = 115
    delay(10);
  }
}

//void ambilK1() {
//  pict_x = 0;
//  area = 0;
//  float deg1 = 225; //205
//  float deg2 = 35; //70
//  float xFront = 53;
//  float yFront = 57;
//  float xBack = 58;
//  for (int i = 0; i <= 19; i++) {
//    FR(xFront, yFront, 0, 0);
//    BR(xBack, -55, 0, 0);
//    BL3(-(xBack), -55, 0, 0);
//    FL(-(xFront), yFront, 0, 0);
//    dxl.setGoalPosition(14, deg1, UNIT_DEGREE);
//    pegangan.write(deg2);
//    deg1 -= 1;
//    deg2 += 1.75;
//    xFront -= 2.563; //tujuan = 1.74
//    yFront += 2.3205; //tujuan = 103.41
//    xBack += 2.85; // tujuan = 115
//    delay(18);
//  }
//}

void balik() {
  float deg4 = 55; //70
  float deg5 = 205; //57
  float xFront = 1.74;
  float yFront = 103.41;
  float xBack = 115;
  for (int i = 0; i <= 19; i++) {
    FR(xFront, yFront, 0, 0);
    BR(xBack, -55, 0, 0);
    BL(-(xBack), -55, 0, 0);
    FL(-(xFront), yFront, 0, 0);
    xFront += 2.563; //tujuan = 1.74
    yFront -= 2.3205; //tujuan = 103.41
    xBack -= 2.85; // tujuan = 115
    dxl.setGoalPosition(14, deg5, UNIT_DEGREE);
    pegangan.write(deg4);
    deg5 -= 7.4;
    deg4 += 0.75;
    delay(10);
  }
  digitalWrite(PB9, LOW);
}


void nyapit() {
  capit.write(110);
  pegangan.write(55);
}
