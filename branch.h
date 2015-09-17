#include <stdint.h>

/**
* \brief <center><b>BEQ Salto si es igual</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BEQ(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BNE Salto si no es igual</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BNE(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BCS Salto si es mayor o igual (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BCS(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BCC salto si es menor (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BCC(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BMI Salto si es negativo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BMI(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BPL Salto si es positivo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BPL(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BVS Salto si hay sobreflujo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BVS(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BVC Salto si no hay sobreflujo</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BVC(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BHI Salto si es mayor (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BHI(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BLS Salto si es menor o igual (sin signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BLS(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BGE Salto si es mayor o igual (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BGE(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BLT Salto si es menor (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BLT(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BGT Salto si es mayor (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BGT(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BLE Salto si es menor o igual (con signo)</b></center>
* \param *R_Banderas Puntero para el registro de las banderas
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BLE(char *R_Banderas,uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BAL Salto sin condicion, de cualquier forma</b></center>
* \param *Registro Puntero a el registro
* \param Posicion Siguiente posicion
* \return Indicativo si se cumple el salto o no
*/ 
char BAL(uint32_t *Registro,uint32_t Posicion);

/**
* \brief <center><b>BL Salto guardando posicion instruccion siguiente en LR</b></center>
* \param *Registro Puntero a el registro 
* \param Posicion Siguiente posicion
*/ 
void BL(uint32_t *Registro,uint32_t Posicion); 

/**
* \brief <center><b>BX Salta a la posicion guardada en LR</b></center>
* \param *Registro Puntero a el registro
*/ 
void BX(uint32_t *Registro);