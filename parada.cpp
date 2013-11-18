#include <stdio.h>
#include <stack>

using namespace std;

#define MAX_REG		   10
#define MAX_INSTRUCOES 100
#define MAX_VALOR      1000

/**
 * Tipos enumerados para comparações (otimização simples)
 */
enum TpOperador
{
	OpConstante = 0,
	OpRegistrador = 1
};

enum TpComando
{
	MOV  = 242, ADD   = 201,  SUB   = 234,
	MUL  = 238, DIV   = 227,  MOD   = 224,
	IFEQ = 293, IFNEQ = 371,  IFG   = 214,
	IFL  = 219, IFGE  = 283,  IFLE  = 288,
	CALL = 284, RET   = 235,  ENDIF = 358
};

//-----------------------------------------------------------------------------------------------

/**
 * Estrutura para os registradores
 */
typedef struct
{
	unsigned short int R[MAX_REG];
} RegValues;
//-----------------------------------------------------------------------------------------------

/**
 * Estrutura para uma instrução de memória junto
 * com seu cache de registradores
 */
typedef struct
{
	/* Instrução */
	TpComando cmd;
	unsigned int op1;
	TpOperador tp_op2; /* indica se o segundo operador é um registrador ou um  valor */
	unsigned int op2;
	
	/* Cache de valores para tratar a instrucao CALL */
	bool Cache[MAX_VALOR];
} MemSlot;
//-----------------------------------------------------------------------------------------------


int single_hash(char *s)
{
	int tam, i, hash;
	
	tam = strlen(s);
	for (i = 0, hash = 0; i < tam; i++)
	{
		hash += s[i];
	}
	
	return hash;
}
//-----------------------------------------------------------------------------------------------

int main(void)
{
	RegValues cpu;				    /* cpu                 */
	MemSlot mem[MAX_INSTRUCOES];	/* memoria             */
	MemSlot *instr;                 /* instrucao atual     */
	unsigned short int pc;			/* program counter :-) */
	unsigned int tam_mem, argv;
	unsigned int i, valor, saltar;
	stack<int> call_stack;
	unsigned char cmd[6], op1[5], op2[5];
	unsigned short end;
	
	while (1)
	{
		scanf ("%d %d ", &tam_mem, &argv);
		
		
		if (!tam_mem && !argv) break;
		
		/**
		 * Aqui eu limpo a memória, mais tenho que lembrar de limpar os <map> quando termina
		 * cada caso de testes.
		 */
		memset (mem, 0, sizeof(mem));
		
		for (i = 0; i < tam_mem; i++)
		{
			scanf ("%s ", cmd);
			
			mem[i].cmd = TpComando(single_hash((char *)cmd));

			/**
			 * Leis os operadores de acordo com a instrução
			 */
			if (mem[i].cmd != ENDIF)
			{
				if ( (mem[i].cmd != CALL) && (mem[i].cmd != RET) )
					scanf ("%[^,],%s", op1, op2);
				else
					scanf ("%s", op1);
			}
			
			/**
			 * Atualizo a instrução em memória de acordo com o operador
			 */
			mem[i].op1 = (op1[1] - '0');

			if (op2[0] == 'R')
			{
				mem[i].op2 = (op2[1] - '0');
				mem[i].tp_op2 = OpRegistrador;
			}
			else
			{
				mem[i].op2 = atoi((char *)op2);
				mem[i].tp_op2 = OpConstante;
			}
			
			// printf ("%s %d %d %d\n", cmd, mem[i].op1, mem[i].op2);
			
		}
				
		/**
		 * Inicia a simulação
		 */
		memset(&cpu, 0, sizeof(cpu));
		pc = 0;
		cpu.R[0] = argv;
		end = 0;

		while (!end)
		{
			// printf ("[ pc = %d ]\n", pc);
			instr = &mem[pc];			
			valor = ((instr->tp_op2 == OpConstante) ? instr->op2 : cpu.R[instr->op2]);
			pc++;
			saltar = 0;

			switch (instr->cmd)
			{
				/**
				 * Operacoes aritmeticas
				 */
				case MOV:
					cpu.R[instr->op1] = valor;
				break;

				case ADD:
					cpu.R[instr->op1] += valor;
				break;

				case SUB:
					cpu.R[instr->op1] -= valor;
				break;

				case MUL:
					cpu.R[instr->op1] *= valor;
				break;

				case DIV:
					if (valor == 0)
						cpu.R[instr->op1] = 0;
					else
						cpu.R[instr->op1] /= valor;
				break;

				case MOD:
					if (valor == 0)
						cpu.R[instr->op1] = 0;
					else
						cpu.R[instr->op1] %= valor;
				break;

				/**
				 * Operacoes condicionais
				 */
				case IFEQ:
					saltar = (cpu.R[instr->op1] != valor);					
				break;

				case IFNEQ:
					saltar = (cpu.R[instr->op1] == valor);
				break;

				case IFG:
					saltar = (cpu.R[instr->op1] <= valor);
				break;

				case IFL:
					saltar = (cpu.R[instr->op1] >= valor);
				break;

				case IFGE:
					saltar = (cpu.R[instr->op1] < valor);
				break;

				case IFLE:
					saltar = (cpu.R[instr->op1] > valor);
				break;

				/**
				 * Estruturas de subrotinas
				 */
				case CALL:
					printf ("CALL:\n");
					/**
					 * Aqui eu verifico se ele já chamou essa subrotina passando o mesmo parametro antes.
					 * Grato ao Raphael Menderico e ao Davi Costa pela dica.
					 */
					if (instr->Cache[cpu.R[instr->op1]])
					{
						printf ("*\n");
						end = 1;
					}
					else
					{
						call_stack.push(pc);
						pc = 0;
						cpu.R[0] = cpu.R[instr->op1]; // argv
						
						instr->Cache[cpu.R[instr->op1]] = 1;
					}
				break;

				case RET:
					printf ("RET:\n");
					if (call_stack.size())
					{
						pc = call_stack.top();
					}
					else
					{
						printf ("%d\n", cpu.R[instr->op1]);
						end = 1;
					}
				break;
				
				/**
				 * Sobrou. Coloquei aqui pra não gerar warning.
				 */
				default:
				break;
			}
			
			if (saltar)
			{
				do
				{
					instr = &mem[pc];			
					valor = ((instr->tp_op2 == OpConstante) ? instr->op2 : cpu.R[instr->op2]);
					pc++;
				}
				while ( (instr->cmd != ENDIF) );
			}

			cpu.R[instr->op1] %= MAX_VALOR;

			for (i = 0; i < 10; i++)
				printf ("R%d = %d / ", i, cpu.R[i]);
			printf ("\n");

		}
	}

	return 0;
}
