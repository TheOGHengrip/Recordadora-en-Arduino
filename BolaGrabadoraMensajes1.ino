#define REC 2 // Pin de grabacion REC
#define PLAY_E 3 // Pin de reproduccion PLAYE 
#define BOTON_PLAY 4 // Pin de boton para iniciar play en PLAYE
#define BOTON_REC 5 // Pin de boton para grabar a REC
#define LED_BLANCO 6 // Pin led blanco
#define LED_ROJO 7 // Pin led rojo
#define playTime 5000 // Tiempo de espera mientras se reproduce el mensaje grabado
#define recordTime 8000 // Tiempo de espera mientras se graba mensaje

int escuchado = 1; //Cuando es 0 hay un mensaje grabado, cuando es 1 ya se escucho el mensaje

void setup() 
{
  pinMode(REC, OUTPUT);  // Salida en REC
  digitalWrite(REC, LOW); // Apagar REC
  pinMode(PLAY_E, OUTPUT);  // Salida en PLAYE
  digitalWrite(PLAY_E, LOW); // Apagar PLAYE
  pinMode(LED_BLANCO, OUTPUT);  // Salida en led blanco
  digitalWrite(LED_BLANCO, HIGH); // Encender led blanco
  pinMode(LED_ROJO, OUTPUT);  // Salida en led rojo
  digitalWrite(LED_ROJO, LOW); // Apagar led rojo

  pinMode(BOTON_REC, INPUT);  // Entrada en boton grabar
  digitalWrite(BOTON_REC, HIGH); // Pull up boton grabar
  pinMode(BOTON_PLAY, INPUT);  // Entrada en boton play
  digitalWrite(BOTON_PLAY, HIGH); // Pull up boton play
}

void loop() 
{
  int BOTON_REC_STATUS = digitalRead(BOTON_REC);   //Leer boton grabar
  int BOTON_PLAY_STATUS = digitalRead(BOTON_PLAY); //Leer boton play
    
  if(BOTON_REC_STATUS == LOW && BOTON_PLAY_STATUS == HIGH && escuchado == 1) //Mientras se graba audio todos los led se apagan
  {       
    digitalWrite(LED_BLANCO, LOW); // Apagar led blanco al comenzar a grabar
    escuchado = 0;            // Indicar que no se ha escuchado el audio
    digitalWrite(REC, HIGH);  // Encender pin REC
    delay(recordTime);        // Grabar audio
    digitalWrite(REC, LOW);   // Apagar pin REC  
    digitalWrite(LED_ROJO, HIGH); // Encender led rojo al terminar de grabar
  } 
  
  if(BOTON_PLAY_STATUS == LOW && BOTON_REC_STATUS == HIGH && escuchado == 0) //Mientras se reproduce audio todos los led se apagan
  {
    digitalWrite(LED_ROJO, LOW); // Apagar led rojo al empezar a escuchar
    escuchado = 1;              // Indicar que ya se escuchó el audio
    digitalWrite(PLAY_E, HIGH); // Encender pin PLAYE
    delay(50);                  // Esperar 50 milisegundos con el PLAYE encendido
    digitalWrite(PLAY_E, LOW);  // Apagar pin PLAYE 
    delay(playTime);            //Esperar el tiempo de reproduccion de sonido
    digitalWrite(LED_BLANCO, HIGH); // Encender led blanco al terminar de escuchar   
  }             
}
