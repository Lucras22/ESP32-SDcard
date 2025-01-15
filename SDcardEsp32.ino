
#include <SPI.h>
#include <SD.h>

File myFile;
const int CS = 5;

const char * dados = R"(Lucas Galindo é um desenvolvedor focado na area de sistemas embarcados onde o mesmo trabalha com automação de processos que requerem uma coleta de dados precisos)";

String generateFileName(const char *baseName) {
  int fileNumber = 0;
  String fileName;
  // Incrementa o número no final do nome até encontrar um arquivo que não exista
  do {
    fileName = String("/") + baseName + fileNumber + ".txt";
    fileNumber++;
  } while (SD.exists(fileName.c_str()));
  return fileName;
}

void WriteFile(const char *path, const char *message) {
  // Abre o arquivo para escrita
  myFile = SD.open(path, FILE_WRITE);
  if (myFile) {
    Serial.printf("Escrevendo no arquivo %s ", path);
    myFile.println(message);
    myFile.close();
    Serial.println("concluído.");
  } else {
    Serial.println("Erro ao abrir o arquivo ");
    Serial.println(path);
  }
}

void ReadFile(const char *path) {
  // Abre o arquivo para leitura
  myFile = SD.open(path);
  if (myFile) {
    Serial.printf("Lendo o arquivo %s\n", path);
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("Erro ao abrir o arquivo ");
    Serial.println(path);
  }
}

void setup() {
  Serial.begin(9600);
  delay(500);
  while (!Serial) { ; } // Aguarda a inicialização do monitor serial

  Serial.println("Inicializando o cartão SD...");
  if (!SD.begin(CS)) {
    Serial.println("Falha na inicialização!");
    return;
  }
  Serial.println("Inicialização concluída.");

  // Gera um nome de arquivo único e salva os dados
  String fileName = generateFileName("DevLucasGalindo");
  WriteFile(fileName.c_str(), dados);
  // Lê e imprime os dados salvos
  ReadFile(fileName.c_str());
}

void loop() {
  // Não há código no loop
}
