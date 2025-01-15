# Descrição do Projeto

Este projeto demonstra como realizar armazenamento local de dados utilizando um cartão SD conectado a um microcontrolador (como o ESP32 ou Arduino). O sistema permite gravar, organizar e recuperar informações de forma eficiente, mesmo na ausência de conectividade com um servidor remoto.

O foco principal é garantir que nenhum dado crítico seja perdido em caso de falhas na conexão ou interrupções no sistema, tornando este código ideal para aplicações em hidroponia, estações meteorológicas ou sistemas de monitoramento remoto.

# Funcionamento

### 📂 Armazenamento de Dados

- Nome de Arquivo Dinâmico: Cada arquivo recebe um nome único, gerado automaticamente com base em um nome-base e incrementado numericamente. Isso evita conflitos com nomes existentes no cartão SD.
- Escrita de Dados: Informações são gravadas em um arquivo recém-criado, possibilitando fácil organização e rastreamento dos registros.
- Leitura de Dados: O conteúdo do arquivo pode ser lido e exibido no monitor serial.

### 🛠 Estrutura do Código
- Inicialização do SD: O sistema verifica se o cartão SD está disponível e pronto para uso.
- Escrita no SD: Dados são escritos no arquivo com o nome gerado pela função generateFileName.
- Leitura do SD: Informações salvas são exibidas diretamente no monitor serial, garantindo que as leituras sejam facilmente auditadas.

# Aplicações
O código é flexível e pode ser adaptado para diversas áreas que exigem coleta e armazenamento de dados, como:

- Hidroponia: Monitoramento de sensores como temperatura, TDS, e pH para controle da solução nutritiva.
- Estação Meteorológica: Registro de dados climáticos (temperatura, umidade, índice UV, chuva).
- Agricultura de Precisão: Armazenamento de dados sobre solo, água e clima.
- Automação Residencial: Histórico de consumo de energia ou monitoramento de condições ambientais internas.

## Benefícios do Armazenamento Local
- Redundância de Dados: Em caso de falha na conectividade com servidores, as informações são preservadas no cartão SD.
- Persistência de Informações: Garantia de histórico acessível a qualquer momento para análise.
- Flexibilidade: Dados podem ser facilmente recuperados ou exportados.

# Como Usar
### Componentes Necessários:

- Microcontrolador ESP32 
- Módulo SD
- Cartão SD
- Configuração de Hardware:

Conecte o módulo SD ao microcontrolador. Certifique-se de configurar o pino CS corretamente no código.
![image](https://github.com/user-attachments/assets/f4599e96-12ce-4e48-8884-57b3540ee7ab)

### Uso do Código:
Faça upload do sketch para o microcontrolador.
Insira um cartão SD no módulo e abra o monitor serial para observar as mensagens.
