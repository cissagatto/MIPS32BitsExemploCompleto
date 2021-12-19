# COMPILANDO UM PROGRAMA COMPLEXO EM C PARA MIPS
 
# SEGMENTO DE DADOS
# Os itens subsequentes são armazenados no segmento de dados no próximo endereço disponível 
.data
	# VETORES
	# cada vetor vai armazenar 5 valores do tipo inteiro
	# fazer 5 * 4 =20 para saber o tamanho a que precisa armazenar	
			.align 4                    # alinhamento
	vetor_g:        .space 20                   # cria um vetor de 5 inteiros
	vetor_f:	.word  1, 2, 3, 4, 5        # cria e inicializa o vetor f
	vetor_c:	.word  9, 19, 11, 8, 20     # cria e inicializa o vetor c
        vetor_e:	.word  8, 4, 3, 9, 10       # cria e inicializa o vetor e
        tamanho:	.space 20                   # tamanho dos vetores 4*5 inteiros = 20
        fibs: 		.word  0:12                 # vetor com 12 inteiro
	size_fibs: 	.word  12                   # tamanho do array
        matriz_h:	.word 2, 5
                        .word 3, 7
        size:           .word 2
	.eqv		DATA_SIZE 4


        # NOP is the assembly idiom used to denote no operation 
        # The actual instruction is interpreted by the hardware as SLL r0, r0, 0                
        # branch delay slot - No Operation
        nop 
        
        # tabela de saltos
       			.align 2                                   # alinhamento
	casos:          .word caso1
			.word caso2
			.word caso3
			.word caso4
			.word caso5
			.word caso6
			.word default
        
	# TODA AS MENSAGENS DE TEXTO QUE APARECERÃO NO CONSOLE
	som: 	.asciiz "\n\tA soma é: "
	med:	.asciiz "\n\tA média é: "
	indice:	.asciiz "\n\tO indice é: "	
	ab1: 	.asciiz "\n\ta é igual a b!"
	ab2: 	.asciiz "\n\ta não é igual a b!"
	ab3: 	.asciiz "\n\ta é menor que b!"
	ab4: 	.asciiz "\n\ta não é menor que b!"
	c1: 	.asciiz "\n\tResultado Soma: "
	c2: 	.asciiz "\n\tResultado OU: "	
	c3: 	.asciiz "\n\tResultado E: "
	c4: 	.asciiz "\n\tResultado Subtração: "
	c5: 	.asciiz "\n\tResultado Multiplicação: "	
	m1:	.asciiz "\n\tDigite o valor de a: "
	m2:	.asciiz "\n\tDigite o valor de b: "  
	m3:	.asciiz "\n\tDigite o valor de d: " 
	m4:	.asciiz "\n\tEscolha uma opção: \n\t0. If Simples; \n\t1. If Composto; \n\t2. Loop For; \n\t3. Loop While; \n\t4. Matriz \n\t5. Recursao \n\tDigite o número desejado: " 
        m0:     .asciiz "\n\tOpção escolhida: "
	m5:	.asciiz "\n\tIF SIMPLES"
	m6:	.asciiz "\n\tIF COMPOSTO"
	m7:	.asciiz "\n\tLOOP FOR"
	m8:	.asciiz "\n\tLOOP WHILE\n"
	m9:	.asciiz "\n\tMATRIZ\n"
	m10:	.asciiz "\n\tOpção inválida"	
	m11:	.asciiz "\n\tValor inválido"	
	m12:	.asciiz "\n\tFim da função"	
	m13:	.asciiz "\n\tElemento: "	
	m14:	.asciiz "\n\tExemplo de recursão usando FIBONACI!\n"	
	newLine: .asciiz "\n\t"	
	space_fibs:     .asciiz  " "          # space to insert between numbers
	head_fibs:      .asciiz  "\tThe Fibonacci numbers are:\n"
	
# SEGMENTO DE TEXTO
.text

# Declara os rótulos listados como globais para serem utilizados
# em outras partes do código (e arquivos)
.globl main, se_simples, se_composto, loop_for, loop_while, matriz, fibonaci
	
# PROGRAMA PRINCIPAL
	main:
		# setando a pilha de chamada de procedimentos
		subu $sp, $sp, 32   # o frame de pilha tenm 32 bytes
		sw $ra, 20($sp)     # salva o endereço de retorno
		sw $fp, 16($sp)     # salva o ponteiro do frame
		addiu $sp, $sp, 28  # prepara o ponteiro do frame
					
		# SOLICITA AS ENTRADAS PELO TECLADO		
		# pedindo o valor de a ($s0)
		li $v0, 4   # 4 é o código do sistema para string
		la $a0, m1  # pega o rótulo M1 e coloca no argumento
		syscall     # chamada do sistema		
		# pegando o que o usuário digitou no console
		li $v0, 5      # 5 é o código do sistema para inteiro
		syscall        # chamada do sistema 
		move $s0, $v0  # aqui move o conteúdo digitado para o registrador temporário		

		# pedindo o valor de b ($s1)
		li $v0, 4   
		la $a0, m2  
		syscall    
		# pegando b digitado
		li $v0, 5     
		syscall        
		move $s1, $v0  
		
		# pedindo o valor de d ($s2)
		li $v0, 4   
		la $a0, m3  
		syscall     		
		# pegando d digitado
		li $v0, 5     
		syscall        
		move $s2, $v0  
		
		# pedindo o valor de op ($s3)
		li $v0, 4   
		la $a0, m4  
		syscall  
		# pegando a opção que o usuário digitou na tela
		li $v0, 5     
		syscall        
		move $s3, $v0		
		
		# imprime texto
		li $v0, 4   
		la $a0, m0
		syscall 
		# imprime a opção escolhida pelo usuário  	
		li $v0,1    
		move $a0, $s3
		syscall 
		
		# Verificando se o valor digitado para OP ($s3) é válido 
		# OP tem que ser IGUAL OU MAIOR que zero para ser válido
		# lembrando que a contagem começa no ZERO
		# Verificando os limites de OP		
		# verifica se OP < 0
		li   $s5, 0
		slt  $t3, $s3, $s5       # s3 < 0 ? 
		bne  $t3, $zero, FIM     # se s3 é menor que 1 sai do programa     
		# verifica se OP > 
		li   $s5, 6
		slt  $t3, $s3, $s5        # s3 > 6 ?             
		beq  $t3, $zero, FIM      # se s3 é maior que 6 sai do programa
		
		# SWITCH-CASE
		# Calculando o endereço correto do Label
		la  $s4, casos      
		sll $t1, $s3, 2                         
		add $t1, $t1, $s4                    
		lw  $t0, 0($t1)  
		jr  $t0	               # pula para o endereço correto
			
		# CASOS
		
		# CASO 1 É O IF SIMPLES
		caso1:
			# printa mensagem no console
			li $v0, 4
			la $a0, m5
			syscall
		
			# chama a função			
			move $a0, $s0     # carrega a variavel a
			move $a1, $s1     # carrega a variavel b
			la $a2, vetor_c   # carrega o vetor c			
			la $a3, vetor_e   # carrega o vetor e			
			jal se_simples    # chama a função
			move $t1, $v0     # libera $v0									

			j FIM

		# CASO 2 É O IF COMPOSTO
		caso2:
			# printa mensagem no console	
			li $v0, 4
			la $a0, m6
			syscall
			
			# chama a função
			move $a0, $s0	# carrega a variavel a
			move $a1, $s1 	# carrega a variavel b
			move $a2, $s2 	# carrega a variavel d
			la $a3, vetor_e # carrega o vetor e			
			jal se_composto # chama a função
			move $t1, $v0   # restaura argumentos
			
			j FIM	
			
		# CASO 3 É O FOR		
		caso3:
			# printa mensagem no console	
			li $v0, 4
			la $a0, m7
			syscall
			
			# chama a função
			la $a3, vetor_f  # carrega o vetor e			
			jal loop_for     # chama a função
			move $t1, $v0    # restaura argumentos
			
			j FIM	
		
		# CASO 4 É WHILE
		caso4:
			# printa mensagem no console
			li $v0, 4
			la $a0, m8
			syscall
			
			# chama a função
			move $a0, $s0    # carrega a variavel a
			move $a1, $s1    # carrega a variavel b
			la $a2, vetor_c  # carrega o vetor c			
			la $a3, vetor_e  # carrega o vetor e			
			jal loop_while   # chama a função
			move $t1, $v0    # restaura argumentos
			
			j FIM	

		# CASO 5 É A MATRIZ
		caso5:
			# printa mensagem no console
			li $v0, 4
			la $a0, m9
			syscall
			
			# chama a função
			la $a0, matriz_h # carrega o vetor 
			lw $a1, size     # carrega o tamanho
			jal matriz       # chama a função
			move $a0, $v0
			li $v0, 1			
			syscall							
			li $v0, 4
			la $a0, newLine
			syscall
							
			j FIM	
			
		# CASO 6 É RECURSÃO
		caso6:
			# printa mensagem no console
			li $v0, 4
			la $a0, m14
			syscall			
		
			jal fibonaci    # chama a função
			move $t1, $v0    # restaura argumentos
			
			j FIM
		
		default: 
			# printa mensagem no console
			li $v0, 4
			la $a0, m10
			syscall	
			j FIM
		
		# re-setando a pilha de chamada de procedimentos
		lw $ra, 20($sp)       # restaura o endereço
		lw $fp, 16($sp)       # restaura o frame pointer
		addiu $sp, $sp, 32    # remove do frame		
		j FIM	              # finaliza o programa		

# FUNÇÕES

	se_simples:
		# configurações da pilha
		subu  $sp, $sp, 32   # reserva o espaço do frame ($sp)    
		sw    $ra, 20($sp)   # salva o endereço de retorno ($ra)    
		sw    $fp, 16($sp)   # salva o frame pointer ($fp)    
		addiu $fp, $sp, 28   # prepara o frame pointer    
		sw    $a0, 0($fp)    # salva o argumento ($a0)	
		
		# corpo da função		
		move $t0, $a0 # a
		move $t1, $a1 # b
		lw $t2, 0($a2) # carregando c[0]		
						
		bne $t0, $t1, FIM_FUNCAO   # primeiro argumento == segundo argumento?
		add $t4, $t1, $t2    # somando B com C[0]
		or $t5, $t4, $t1     # calculando OR
		sw $t5, 0($a3)	     # armazenando em E[0]
		
		# PRINTANDO
		li $v0, 4    
		la $a0, ab1
		syscall      
		li $v0, 4    
		la $a0, c1
		syscall     		
		li $v0,1    
		move $a0, $t4  
		syscall 			
		li $v0, 4    
		la $a0, c2
		syscall     		
		li $v0,1    
		move $a0, $t5  
		syscall 
					 	
		# configurações do procedimento    
		add $v0, $s1, $zero # retorna para quem chamou    
		#jr $ra	
		j FIM
	
	se_composto:    
		# configurações da pilha
		subu  $sp, $sp, 32   # reserva o espaço do frame ($sp)    
		sw    $ra, 20($sp)   # salva o endereço de retorno ($ra)    
		sw    $fp, 16($sp)   # salva o frame pointer ($fp)    
		addiu $fp, $sp, 28   # prepara o frame pointer    
		sw    $a0, 0($fp)    # salva o argumento ($a0)	
		
		# corpo da função
		move $t0, $a0 # a
		move $t1, $a1 # b
		move $t2, $a2 # d
						
		beq $t0, $t1, ELSE   # desvia se t0 == t1
		
		# a não é igual a b
		li $v0, 4    
		la $a0, ab2 
		syscall   
		
		add $t4, $t2, $t1    # t4 = t2 + t1
		addi $t5, $t5, 0     # t5 = 0
		lw $t4, vetor_e($t5) # e[0] = t4
		
		# resultado soma                
		li $v0, 4    
		la $a0, c1 
		syscall     	
		li $v0,1    
		move $a0, $t4  
		syscall 
		
		and $t6, $t2, $t1    # t6 = t2 AND t1
		addi $t5, $t5, 4     # t5 = t5 + 4
		sw $t6, vetor_e($t5) # e[1] = t6
					
		# resultado AND 
		li $v0, 4    
		la $a0, c3
		syscall     		
		li $v0,1    
		move $a0, $t6  
		syscall
		
		j FIM
		
		ELSE:
			# a é igual a 
			li $v0, 4    
			la $a0, ab1
			syscall    		  

			sub $t4, $t2, $t1     # t4 = t2 + t1
   		        addi $t5, $t5, 0      # t5 = t5 + 0
			sw $t4, vetor_e($t5)  # e[0] = t4			

			li $v0, 4    
			la $a0, c4
			syscall     		
			li $v0,1    
			move $a0, $t4  
			syscall 
			
			add $t6, $t2, $t1     # t6 = t2 + t1
			addi $t5, $t5, 4      # t5 = t5 + 4
			sw $t6, vetor_e($t5)  # e[1] = t6
			
			# soma			
			li $v0, 4    
			la $a0, c1
			syscall     		
			li $v0,1    
			move $a0, $t6 
			syscall
			
			j FIM 			

		# configurações do procedimento    
		add $v0, $s1, $zero # retorna para quem chamou    
		# jr $ra	
		j FIM
	
	loop_for:
		subu  $sp, $sp, 32   # reserva o espaço do frame ($sp)    
		sw    $ra, 20($sp)   # salva o endereço de retorno ($ra)    
		sw    $fp, 16($sp)   # salva o frame pointer ($fp)    
		addiu $fp, $sp, 28   # prepara o frame pointer    
		sw    $a0, 0($fp)    # salva o argumento ($a0)	
		
		la $s4, vetor_f      # indice do vetor ($s4 é o vetor f)                
		addiu $s3, $s3, 5    # número total de elementos no vetor ($s3 = 4*5=20)   
		addi $s1, $s1, 0            # soma = 0 ($s1 é a soma) 		
		move $s0, $zero      # i = 0 ($s0 é i)		
		
		LOOP1:      
			# configurações do FOR      
			bge $s0, $s3, FIM_FUNCAO # desvie se $s0 >= $s3 ($s0 é i) [i >= 5?]

			# configurações do ARRAY      
		        sll $t1, $s0, 2      # $t1 = 4 * i (4 * $s0)      
		        add $t2, $s4, $t1    # t2 = ( vetor + ( 4 * i) )      
		        lw $t3, 0($t2)       # $t3 = vetor[i]      
		        add $s1, $s1, $t3    # somando os elementos (soma = soma + vetor[i]   
		        
			# printando
			li $v0, 4    
			la $a0, som  
			syscall      
			
			li $v0,1    
			move $a0, $s1  
			syscall 
			
			li $v0, 4    
			la $a0, indice  
			syscall  

			li $v0,1    
			move $a0, $s0  
			syscall 
									
			# configurações do FOR      
			addi $s0, $s0, 1  # $s0 = $s0 + 1 (i = i + 1)   		
						            
			j LOOP1            # volta para o LOOP
						
		# configurações do procedimento    
		add $v0, $s1, $zero # retorna para quem chamou            	
		# nop
		jr $ra
		#j FIM	
			
	loop_while:
		# configurações da pilha
		subu  $sp, $sp, 32   # reserva o espaço do frame ($sp)    
		sw    $ra, 20($sp)   # salva o endereço de retorno ($ra)    
		sw    $fp, 16($sp)   # salva o frame pointer ($fp)    
		addiu $fp, $sp, 28   # prepara o frame pointer    
		sw    $a0, 0($fp)    # salva o argumento ($a0)	
		
		# definindo os valores que serão armazenados no vetor
		addi $s0, $zero, 30
		addi $s1, $zero, 45				
		addi $s2, $zero, 12			
		addi $s3, $zero, 50
		addi $s4, $zero, 94

   	        # carregando valores que serão armazenados no vetor		
		addi $t0, $zero, 0   # t0 = 0 - 0 - 30
		sw $s0, vetor_g($t0)
		addi $t0, $t0, 4     # t0 = 1 - 4 - 45
		sw $s1, vetor_g($t0)
    		addi $t0, $t0, 4     # t0 = 2 - 8 - 12
		sw $s2, vetor_g($t0)		    	
    		addi $t0, $t0, 4     # t0 = 2 - 16 - 50
    		sw $s3, vetor_g($t0)		    	
    		addi $t0, $t0, 4     # t0 = 2 - 16 - 94
    		sw $s4, vetor_g($t0)		    	
    				    				
		addi $t0, $zero, 0   # t0 = 0				
		addi $t6, $t6, 20    # t6 = 20		
					
		LOOP2:				        
			beq $t0, $t6, FIM_FUNCAO # desvia se t0 = t6
			lw $t7, vetor_g($t0)
			
			li $v0, 4
			la $a0, newLine
			syscall
			
			li $v0, 1
			move $a0, $t7
			syscall

			addi $t0, $t0, 4 # t0 = t0 + 4
		
			j LOOP2
			
		# configurações do procedimento    
		add $v0, $s1, $zero # retorna para quem chamou    
		# jr $ra	
		j FIM	
	
	
	matriz:	
		li $v0, 0  # soma = 0
		li $t0, 0  # indice
		
		sumLoop:
         		# calcula o endereço correto da matriz
		        # addr = baseAddr + (rowIndex * colSize + colIndex) * data_size
			mul $t1, $t0, $a1  # t1 = t0 * a1 --> rowIndex * colSize
			add $t1, $t1, $t0  # t1 = t1 + t0 --> rowIndex * colSize + colIndex
			mul $t1, $t1, DATA_SIZE # t1 = t1 * data-size --> rowIndex * colSize + colIndex) * data_size
			add $t1, $t1, $a0       # t1 = t1 + a0 --> baseAddr + (rowIndex * colSize + colIndex) * data_size
			lw $t2, ($t1)           
			add $v0, $v0, $t2       # soma = soma + array[][]			
			addi $t0, $t0, 1        # i = i + 1	
			blt $t0, $a1, sumLoop   # i < tamanho		
		jr $ra		
		#j FIM
		
	fibonaci:
		
		la    $t0, fibs        # load address of array
		la    $t5, size_fibs   # load address of size variable
		lw    $t5, 0($t5)      # load array size
		li    $t2, 1           # 1 is first and second Fib. number
		add.d $f0, $f2, $f4
		sw    $t2, 0($t0)      # F[0] = 1
		sw    $t2, 4($t0)      # F[1] = F[0] = 1
		addi  $t1, $t5, -2     # Counter for loop, will execute (size-2) times
		
		loop_fibs: 
			lw   $t3, 0($t0)      # Get value from array F[n] 
			lw   $t4, 4($t0)      # Get value from array F[n+1]
			add  $t2, $t3, $t4    # $t2 = F[n] + F[n+1]
			sw   $t2, 8($t0)      # Store F[n+2] = F[n] + F[n+1] in array
			addi $t0, $t0, 4      # increment address of Fib. number source
			addi $t1, $t1, -1     # decrement loop counter
			bgtz $t1, loop_fibs        # repeat if not finished yet.
			la   $a0, fibs        # first argument for print (array)
			add  $a1, $zero, $t5  # second argument for print (size)
			jal  print            # call print routine. 
		j FIM
		
	print:
		add  $t0, $zero, $a0  # starting address of array
		add  $t1, $zero, $a1  # initialize loop counter to array size
		la   $a0, head_fibs   # load address of print heading
		li   $v0, 4           # specify Print String service
		syscall               # print heading
	out:
		lw   $a0, 0($t0)      # load fibonacci number for syscall
		li   $v0, 1           # specify Print Integer service
		syscall               # print fibonacci number
		la   $a0, space_fibs  # load address of spacer for syscall
		li   $v0, 4           # specify Print String service
		syscall               # output string
		addi $t0, $t0, 4      # increment address
		addi $t1, $t1, -1     # decrement loop counter
		bgtz $t1, out         # repeat if not finished
		jr   $ra              # return	
		#j FIM	
		
	FIM_FUNCAO:
		li $v0, 4    
		la $a0, m12
		syscall
 	
	# encerra o programa corretamente
	FIM:
		li $v0, 10 
		syscall
