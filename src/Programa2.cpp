#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    std::string cmd;

    while (true)
    {
        std::cout << "Insira um comando (ou digite 'sair' para encerrar a execução): " << std::endl
                  << "--> ";
        std::getline(std::cin, cmd);

        if (cmd == "sair")
        {
            break;
        }

        pid_t pid = fork();

        if (pid < 0)
        {
            std::cerr << "Falha no fork" << std::endl;
            return 1;
        }
        else if (pid == 0)
        { // Executa o comando que o usuário digitou apenas no processo filho
            int ret = std::system(cmd.c_str());
            if (ret == -1)
            {
                std::cerr << "Falha ao executar o comando" << std::endl;
                return 1;
            }
            exit(0);
        }
        else
        { // Trata a execução do processo filho dentro do processo pai
            int status;
            waitpid(pid, &status, 0); // Aguarda o fim da execução do processo filho
            if (WIFEXITED(status))
            {
                std::cout << "O processo filho terminou com o status " << WEXITSTATUS(status) << std::endl;
            }
        }
    }

    return 0;
}
