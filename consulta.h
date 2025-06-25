#ifndef CONSULTA_H
#define CONSULTA_H

typedef struct {
    char cpfPaciente[15];
    char data[11];
    char horario[6];
    char problema[100];
    char realizada[4];
} Consulta;

void agendarConsulta();
void listarConsultas();
void listarConsultasPendentes();
void marcarConsultaComoRealizada();
void relatorioConsultasPorPaciente();

#endif
