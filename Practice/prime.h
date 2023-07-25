int is_prime(int variable){
	for(int iter =2;iter<(variable/2);iter++){
		if((variable%iter) == 0)
			return 0;
	}
	return 1;
}

