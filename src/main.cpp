#include <Arduino.h>

#define ZONE_DE_VIGILANCE 200

#define ANGLE_MAT 26.565051

float X = 0, Y = 0, ANGLE = 0; // DEPLACEMENT

float valeur[200][2]; // DETECTION

/*boolean phare(){

}*/

boolean mat(float X, float Y, float Angle){

  float angleM1, angleM2, xM, yM, distanceM;

  xM = X;
  yM = Y - 1500;

  distanceM = pow(xM,2) + pow(yM,2);
  distanceM = sqrt(distanceM);

  if(distanceM < 430 + ZONE_DE_VIGILANCE){
    if(yM >= 0){ // Du coté de l'équipe jaune

      angleM1 = yM/xM;
      angleM1 = atan(angleM1)*180/PI;

      if(angleM1 > ANGLE_MAT){ // Du coté du mat

        angleM1 = xM/distanceM;
        angleM1 = acos(angleM1)*180/PI;

        xM = X + 222;
        yM = Y - 1600;

        distanceM = pow(xM,2) + pow(yM,2);
        distanceM = sqrt(distanceM);
        angleM2 = xM/distanceM;
        angleM2 = acos(angleM2)*180/PI;

        // Déduction de la page d'angle selon la position du robot ( avec 3° de marge )

        angleM1 = 267 - angleM1 ;
        if(angleM1 < 0){
          angleM1+=360;
        }

        if(yM >= 0){
          angleM2 = 273 - angleM2;
          if(angleM2 < 0){
            angleM2+=360;
          }
        }else{
          angleM2 = 273 + angleM2;
          if(angleM2 >= 360){
            angleM2-=360;
          }
        }

        // Traitement
        if (angleM2 > angleM1) {

          if(Angle > angleM1 && Angle < angleM2){
            return true;
          }else{
            return false;
          }

        }else{

          if(Angle > angleM1 && Angle < 360){
            return true;
          }else{
            if (Angle >= 0 && Angle < angleM2){
              return true;
            }else{
              return false;
            }
          }

        }

      }else{ // Au centre
        xM = X + 222;
        yM = Y - 1600;

        distanceM = pow(xM,2) + pow(yM,2);
        distanceM = sqrt(distanceM);
        angleM1 = xM/distanceM;
        angleM1 = acos(angleM1)*180/PI;

        yM = Y - 1400;
        distanceM = pow(xM,2) + pow(yM,2);
        distanceM = sqrt(distanceM);
        angleM2 = xM/distanceM;
        angleM2 = acos(angleM2)*180/PI;

        // Déduction de la page d'angle selon la position du robot ( avec 3° de marge )
        yM = Y - 1600;
        if (yM >= 0) {
          angleM1 = 273 - angleM1;
          if(angleM1 < 0){
            angleM1+=360;
          }
        }else{
          angleM1 = 273 + angleM1;
          if(angleM1 >= 360){
            angleM1-=360;
          }
        }

        angleM2 = 267 - angleM2 ;
        if(angleM2 < 0){
          angleM2+=360;
        }

        // Traitement
        if (angleM1 > angleM2) {

          if(Angle > angleM2 && Angle < angleM1){
            return true;
          }else{
            return false;
          }

        }else{

          if(Angle > angleM2 && Angle < 360){
            return true;
          }else{
            if (Angle >= 0 && Angle < angleM1) {
              return true;
            }else{
              return false;
            }
          }

        }
      }

    }else{ // Du coté de l'équipe bleu

      yM*=-1;
      angleM1 = yM/xM;
      angleM1 = atan(angleM1)*180/PI;

      if(angleM1 > ANGLE_MAT){ // Du coté du mat

        angleM1 = xM/distanceM;
        angleM1 = acos(angleM1)*180/PI;

        xM = X + 222;
        yM = Y - 1400;

        distanceM = pow(xM,2) + pow(yM,2);
        distanceM = sqrt(distanceM);
        angleM2 = xM/distanceM;
        angleM2 = acos(angleM2)*180/PI;

        // Déduction de la plage d'angle selon la position du robot ( avec 3° de marge )
        angleM1 = 273 + angleM1;
        if(angleM1 >= 360){
          angleM1-=360;
        }

        if(yM >= 0){
          angleM2 = 267 - angleM2;
          if(angleM2 < 0){
            angleM2+=360;
          }
        }else{
          angleM2 = 267 + angleM2;
          if(angleM2 >= 360){
            angleM2-=360;
          }
        }

        // Traitement
        if (angleM1 > angleM2) {

          if(Angle > angleM2 && Angle < angleM1){
            return true;
          }else{
            return false;
          }

        }else{
          if(Angle > angleM2 && Angle < 360){
            return true;
          }else{
            if (Angle >= 0 && Angle < angleM1) {
              return true;
            }else{
              return false;
            }
          }
        }

      }else{ // Au centre

        xM = X + 222;
        yM = Y - 1400;
        distanceM = pow(xM,2) + pow(yM,2);
        distanceM = sqrt(distanceM);
        angleM1 = xM/distanceM;
        angleM1 = acos(angleM1)*180/PI;

        yM = 1600 - Y;
        distanceM = pow(xM,2) + pow(yM,2);
        distanceM = sqrt(distanceM);
        angleM2 = xM/distanceM;
        angleM2 = acos(angleM2)*180/PI;

        // Déduction de la page d'angle selon la position du robot ( avec 3° de marge )
        yM = Y - 1400;
        if (yM >= 0) {
          angleM1 = 267 - angleM1;
          if(angleM1 < 0){
            angleM1+=360;
          }
        }else{
          angleM1 = 267 + angleM1;
          if(angleM1 >= 360){
            angleM1-=360;
          }
        }

        angleM2 = 273 + angleM2;
        if(angleM2 >= 360){
          angleM2-=360;
        }

        // Traitement
        if (angleM2 > angleM1) {

          if(Angle > angleM1 && Angle < angleM2){
            return true;
          }else{
            return false;
          }

        }else{

          if(Angle > angleM1 && Angle < 360){
            return true;
          }else{
            if (Angle >= 0 && Angle < angleM2) {
              return true;
            }else{
              return false;
            }
          }

        }

      }

    }
  }else{
    return false;
  }
}

boolean limitesXY(float X, float Y, float Angle, float Distance){
  float xL, yL;

  // Conversion des valeurs obtenues sur les axes X et Y  //
  if (Angle >= 0 && Angle < 90){

    xL = Distance*sin(Angle*PI/180);
    yL = Distance*cos(Angle*PI/180);

  }else{
    if (Angle >= 90 && Angle < 180){

      xL = Distance*sin(Angle*PI/180);
      yL = Distance*(-cos(Angle*PI/180));

    }else{
      if (Angle >= 180 && Angle < 270){

        xL = Distance*(-sin(Angle*PI/180));
        yL = Distance*(-cos(Angle*PI/180));

      }else{
        if (Angle >= 270 && Angle < 360){

          xL = Distance*(-sin(Angle*PI/180));
          yL = Distance*cos(Angle*PI/180);

        }
      }
    }
  }
  // Conversion des valeurs obtenues sur les axes X et Y  //

  if(Angle >= 0 && Angle < 180){ // Droite
    if(xL > 2000-X){
      return true;
    }else{
      if(Angle >= 0 && Angle < 90){ // Haut
        if(yL > 3000-Y){
          return true;
        }else{
          return false;
        }
      }else{ // Bas
        if(yL > Y){
          return true;
        }else{
          return false;
        }
      }
    }
  }else{
    if(Angle >= 180 && Angle < 360){ // Gauche
      if(xL > X){
        return true;
      }else{
        if(Angle >=180 && Angle < 270){ // Bas
          if(yL > Y){
            return true;
          }else{
            return false;
          }
        }else{ // Haut
          if(yL > 3000-Y){
            return true;
          }else{
            return false;
          }
        }
      }
    }
  }
}

boolean obstacle(float X, float Y, float ANGLE, float Distance, float Angle){

  // Prise en compte du sens du robot  //
  if (ANGLE < 0) {
    ANGLE += 360;
  }else{
    if (ANGLE >= 360) {
      ANGLE -= 360;
    }
  }

  Angle+= ANGLE;
  if(Angle >= 360){
    Angle-= 360;
  }

  /*if(phare()){ // Le phare est-il détecté ?
    return false;
  }else{*/
    if(mat(X, Y, Angle)){ // Le mat est-il détecté ?
      return false;
    }else{
      if(limitesXY(X, Y, Angle, Distance)){ // L'exterieur du terrain est-il détecté ?
        return false;
      }else{
        if(Distance > 430 && Distance < 430 + ZONE_DE_VIGILANCE){ // Un obstacle est-il détecté ?
          return true;
        }else{
          return false;
        }
      }
    }
//  }
}

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  int i;

  for(i=0; i<200; i++){
    if(obstacle(X, Y, ANGLE, valeur[i][0], valeur[i][1])){
      //PROCESSUS D'ESQUIVE
    }
  }

}
