#include <cstdlib>
#include <fstream>
#include <iostream>
 
int main()
{
    // Obtem a versao do sistema operacional a partir do arquivo os-release, e usa o comando grep para selecionar apenas a linha que mostra o nome e a versão do sistema
    std::cout << std::system("cat /etc/os-release | grep PRETTY_NAME"); 
    // Le o arquivo com meu nome e numero de matricula
    std::cout << std::ifstream("/MateusHonorato/MateusHonorato.txt").rdbuf();
    // Exibe a saída do comando top, com o argumento -bn1, que otimiza a saída para execução em scripts e determina que o comando imprima a saída uma única vez
    std::cout << std::system("top -bn1");
    // Mostrando a saída do comando ps
    std::cout << std::system("ps"); 
    // Mostrando a saída do comando pstree
    std::cout << std::system("pstree");
    /*
       Usando o comando renice para alterar a prioridade do nosso "Programa1". 
       Para que esse comando funcione é necessário que o codigo seja compilado com "g++ Programa1.cpp -o Programa1"
       Caso o nome do executavel seja diferente, o comando nao vai funcionar
       O comando grep esta sendo usado para separar da saida do comando ps apenas a linha com o pid do Programa 1
       O comando awk seleciona apenas o pid dentro desta linha, para que seja utilizado como arguento do comando renice
    */  
    std::cout << std::system("renice 5 -p $(ps | grep 'Programa1' | awk '{print $1}')");
    /*
       Aqui iremos usar o comando kill para encerrar a execucao do nosso Programa1.
       O funcionamento dos comandos grep e awk segue o mesmo raciocinio do ultimo comando.
       O mesmo resultado poderia ser obtido utilizando os comandos "killall Programa1" ou "pkill Programa1"
       Nao estou utilizando os outros dois comandos pois nao faria sentido ja que somente um vai ser executado 
       e os demais iriam ser ignorados apos a execucao do programa ser encerrada.
    */
    std::cout << std::system("kill $(ps | grep 'Programa1' | awk '{print $1}')");
}