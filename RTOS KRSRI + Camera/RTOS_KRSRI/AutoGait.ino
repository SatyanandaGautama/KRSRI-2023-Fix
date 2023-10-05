//sdtBelok (+) = belok kiri
//sdtBelok (-) = belok kanan
void maju(float lebar, float tinggi, float tSwing, float tStance, int delays, float lStep) {
  float lbr = lStep;
  float tAngkat = (tSwing / 2) - 1;
  float tSeret = tStance - 1;
  float titiktengah = lebar / 5;
  //  movecounter++;
  //  if (movecounter == 1) {
  //FR & BL Swing, FL & BR Seret
  float xSwingFR0 = (55 - lebar) - lbr, xSwingFR1 = (55 + lebar) + lbr;
  float xSwingBL0 = (55 + lebar) - lbr, xSwingBL1 = (55 - lebar) + lbr;
  float xSeretFL0 = 55 + titiktengah, xSeretFL1 = 55 - titiktengah;
  float xSeretBR0 = 55 - titiktengah, xSeretBR1 = 55 + titiktengah;
  //All Legs Seret
  float xSeretFR2 = (55 + lebar) + lbr, xSeretFR3 = 55 + titiktengah;
  float xSeretBL2 = (55 - lebar) + lbr, xSeretBL3 = 55 - titiktengah;
  float xSeretFL2 = 55 - titiktengah, xSeretFL3 = (55 - lebar) + lbr;
  float xSeretBR2 = 55 + titiktengah, xSeretBR3 = (55 + lebar) + lbr;
  //FL & BR Swing, FR & BL Seret
  float xSeretFR4 = 55 + titiktengah, xSeretFR5 = 55 - titiktengah;
  float xSeretBL4 = 55 - titiktengah, xSeretBL5 = 55 + titiktengah;
  float xSwingFL0 = (55 - lebar) + lbr, xSwingFL1 = (55 + lebar) - lbr;
  float xSwingBR0 = (55 + lebar) + lbr, xSwingBR1 = (55 - lebar) - lbr;
  //All Legs Seret
  float xSeretFR6 = 55 - titiktengah, xSeretFR7 = (55 - lebar) - lbr;
  float xSeretBL6 = 55 + titiktengah, xSeretBL7 = (55 + lebar) - lbr;
  float xSeretFL6 = (55 + lebar) - lbr, xSeretFL7 = 55 + titiktengah;
  float xSeretBR6 = (55 - lebar) - lbr, xSeretBR7 = 55 - titiktengah;

  Trayektori(xSwingFR0, xSwingFR1, xSwingBL0, xSwingBL1, xSeretFL0, xSeretFL1, xSeretBR0, xSeretBR1, 55, 55, tinggi, 0, tAngkat, 0.5, tSwing, delays); //Turun //0,5 = tAwal
  Trayektori(xSeretFR2, xSeretFR3, xSeretBL2, xSeretBL3, xSeretFL2, xSeretFL3, xSeretBR2, xSeretBR3, 55, 55, 0, 0, tSeret, 0, tStance, delays);
  Trayektori(xSeretFR4, xSeretFR5, xSeretBL4, xSeretBL5, xSwingFL0, xSwingFL1, xSwingBR0, xSwingBR1, 55, 55, 0, tinggi, tAngkat, 0, tSwing, delays); //Naik

  Trayektori(xSeretFR4, xSeretFR5, xSeretBL4, xSeretBL5, xSwingFL0, xSwingFL1, xSwingBR0, xSwingBR1, 55, 55, 0, tinggi, tAngkat, 0.5, tSwing, delays); //Turun //0,5 = tAwal
  Trayektori(xSeretFR6, xSeretFR7, xSeretBL6, xSeretBL7, xSeretFL6, xSeretFL7, xSeretBR6, xSeretBR7, 55, 55, 0, 0, tSeret, 0, tStance, delays);
  Trayektori(xSwingFR0, xSwingFR1, xSwingBL0, xSwingBL1, xSeretFL0, xSeretFL1, xSeretBR0, xSeretBR1, 55, 55, tinggi, 0, tAngkat, 0, tSwing, delays); //Naik
  //    movecounter == 0;
  //  }
}

void Trayektori(float xFR0, float xFR1, float xBL0, float xBL1, float xFL0, float xFL1, float xBR0, float xBR1, float y0, float y1, float hA, float hB, float tTrayektori, float tAwal, float tTotal, float delays)
{
  //hA = tinggi FR & BL
  //hB = tinggi FL & BR
  float a, b, c, d, e, f, g, h, ii, j, k, l, m, n, o, p;
  float xFR , yFR , zFR , xFL , yFL , zFL, xBL , yBL , zBL, xBR , yBR , zBR;
  float z0Front = height, zpAFront = height + hA, zpBFront = height + hB;
  float z0Back = height2, zpABack = height2 + hA, zpBBack = height2 + hB;
  float z1AFront = (zpAFront - 0.25 * z0Front) / 0.75;
  float z1ABack = (zpABack - 0.25 * z0Back) / 0.75;
  float z1BFront = (zpBFront - 0.25 * z0Front) / 0.75;
  float z1BBack = (zpBBack - 0.25 * z0Back) / 0.75;
  float t = tAwal;
  float iterasi = 1 / tTotal;
  for (int i = 0; i <= tTrayektori; i ++) {
    /////////// KANAN DEPAN (FR)////////////////////
    a = (1 - t) * (1 - t) * (1 - t);
    b = 3 * t * (1 - t) * (1 - t);
    c = 3 * t * t * (1 - t);
    d = t * t * t;
    xFR = a * xFR0 + b * xFR0 + c * xFR1 + d * xFR1;
    yFR = a * y0 + b * y0 + c * y1 + d * y1;
    zFR = a * z0Front + b * z1AFront + c * z1AFront + d * z0Front;
    /////////// KIRI BELAKANG (BL)////////////////
    e = (1 - t) * (1 - t) * (1 - t);
    f = 3 * t * (1 - t) * (1 - t);
    g = 3 * t * t * (1 - t);
    h = t * t * t;
    xBL = e * xBL0 + f * xBL0 + g * xBL1 + h * xBL1;
    yBL = e * y0 + f * y0 + g * y1 + h * y1;
    zBL = e * z0Back + f * z1ABack + g * z1ABack + h * z0Back;
    /////////// KIRI DEPAN (FL)////////////////
    ii = (1 - t) * (1 - t) * (1 - t);
    j = 3 * t * (1 - t) * (1 - t);
    k = 3 * t * t * (1 - t);
    l = t * t * t;
    xFL = ii * xFL0 + j * xFL0 + k * xFL1 + l * xFL1;
    yFL = ii * y0 + j * y0 + k * y1 + l * y1;
    zFL = ii * z0Front + j * z1BFront + k * z1BFront + l * z0Front;
    /////////// KANAN BELAKANG (BR)////////////////
    m = (1 - t) * (1 - t) * (1 - t);
    n = 3 * t * (1 - t) * (1 - t);
    o = 3 * t * t * (1 - t);
    p = t * t * t;
    xBR = m * xBR0 + n * xBR0 + o * xBR1 + p * xBR1;
    yBR = m * y0 + n * y0 + o * y1 + p * y1;
    zBR = m * z0Back + n * z1BBack + o * z1BBack + p * z0Back;

    FRAuto(xFR, yFR, zFR);
    BLAuto(-(xBL), -(yBL), zBL);
    FLAuto(-(xFL), yFL, zFL);
    BRAuto(xBR, -(yBR), zBR);
    t += iterasi;
    delay(delays);
  }
}

void FRAuto(float x, float y, float z) {
  if (x >= 0 && y >= 0) angle1 = round ((atan(y / x) * 57.296) + 180); //Kanan Atas
  sdtcoxa = round(angle1 - legoffset[0]) + 12; //11
  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //71
  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 141; //139
  kanan_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void FLAuto(float x, float y, float z) { //105
  if (x < 0 && y >= 0) angle1 = round (180 + (atan(y / x) * 57.296) + 90); //Kiri Atas
  sdtcoxa = round(angle1 - legoffset[1]) + 13; //18
  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //73
  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 149; //146
  kiri_atas(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("FRONT LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BLAuto(float x, float y, float z) { //195
  if (x < 0 && y < 0) angle1 = round (180 + (atan(y / x) * 57.296) + 180); //Kiri Bawah
  sdtcoxa = round(angle1 - legoffset[2]) + 10; //10

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));

  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //72

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 145; //143
  kiri_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK LEFT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}

void BRAuto(float x, float y, float z) { //105
  if (x >= 0 && y < 0) angle1 = round (360 + (atan(y / x) * 57.296) + 90); //Kanan Bawah
  sdtcoxa = round(angle1 - legoffset[3]) + 15; //15

  P = sqrt((x * x) + (y * y));
  alas = P - cx;
  c = sqrt((alas * alas) + (z * z));
  alpha = atan(z / alas);
  beta = acos((fm * fm + c * c - tb * tb) / (2 * fm * c));
  theta2 = alpha + beta;
  sdtfemur = 90 + round ((theta2 * 57.296)) + 70; //71

  theta3 = acos((tb * tb + fm * fm - c * c) / (2 * tb * fm));
  sdttibia = (90 - (round((theta3 * 57.296) - 90))) + 142; //140
  kanan_bawah(sdtcoxa, sdtfemur, sdttibia);
  // Serial.println("BACK RIGHT :");
  // Serial.print("CX :");
  // Serial.println(sdtcoxa);
  // Serial.print("FM :");
  // Serial.println(sdtfemur);
  // Serial.print("TB :");
  // Serial.println(sdttibia);
}
