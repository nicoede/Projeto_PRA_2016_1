#include "CUnit/Basic.h"
#include"labirinto.h"

void mockup(void){
	CU_ASSERT(0 == 2);
}

void lab_valido(void){
	CU_ASSERT(abrirLabirinto() == 1);
	//imprime_lab();
}

void rato_posicionado(void){
	
	CU_ASSERT(entrar() == 1);
	CU_ASSERT(pRato.x != -1);
	CU_ASSERT(pRato.y != -1);
	
}

void fila_criada(void){
	CU_ASSERT(cria_fila(&f) == 1);
}

void verificou_vizinhos(void){
	CU_ASSERT(verifica_vizinhos(pRato, 1) == 1);
	//imprime_lab();
}

void limpou_labirinto(void){
	CU_ASSERT(limpa_labirinto() == 1);
	//imprime_lab();
}

void procura(void){
	CU_ASSERT(varre_labirinto(1) == 1);
	imprime_lab();
}

void testa_backtrack(void){
	//imprime_lab();
	CU_ASSERT(backtrack(pRato) == 1);
	//imprime_labaux();
}

void percorre(void){
	CU_ASSERT(percorre_labirinto() == 1);
     imprime_labaux();
}

int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if (
   		//(NULL == CU_add_test(pSuite, "labirinto válido", lab_valido))||
   		//(NULL == CU_add_test(pSuite, "rato na entrada", rato_posicionado))||
   		//(NULL == CU_add_test(pSuite, "fila criada", fila_criada))||
   		//(NULL == CU_add_test(pSuite, "verificou vizinhos", verificou_vizinhos))||
   		//(NULL == CU_add_test(pSuite, "limpou labirinto", limpou_labirinto))||
   		//(NULL == CU_add_test(pSuite, "procura queijo/saida", procura))||
   		//(NULL == CU_add_test(pSuite, "testa backtrack", testa_backtrack))||
   		(NULL == CU_add_test(pSuite, "percorre labirinto", percorre))
   		)
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

