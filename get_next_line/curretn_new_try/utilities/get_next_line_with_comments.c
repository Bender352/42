char	*get_next_line(int fd)
{
	static char	*buffer;
	char		ret_line;
	char		temp;
	int			i;
	
	if (read(fd, 0 ,0))
		return (NULL);
	buffer = get_joined_buffer(buffer, fd);
	if(!buffer)												//when get_joined_buffer failed it will forwarde the NULL to the main function
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])					//if buffer has \0(EOF) it stores the position in i
		i++;
	while (buffer[i] == '\n')
		i++;												//add + 1 so to ft_substring cuts behinde the '\n'
	ret_line = ft_substr(buffer, 0, i);						//copies the \n included to ret_line 
	temp = ft_substr(buffer, i, ft_strlen(buffer) - i);		//copies the rest of buffer after \n into a temp buffer.
	free(buffer);											//frees the old buffer
	buffer = temp;											//copies the reste that wasn't included in ret_line to buffer so it gets return in the next cycle.
	return (ret_line);	
}

char	*get_joined_buffer(char *buffer, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	int		i;
	
	i = -1;													//-1 so we can save a line in the next while loop
	while (++i <= BUFFER_SIZE)								//saves a line for i++
		temp[i] = '\0';										//writes every bite of temp to 0
	i = 1;
	while (i && !ft_strchr(temp, '\n'))						//checks if i==0 (EOF) or has found nl
	{
		i = read(fd, temp, BUFFER_SIZE);					//read file into temp
		if (i < 0 || (!i && !buffer))						//checks for exceptions, (!i && !buffer) -> !i if EOF is reached, !buffer when there is nothing in it. (This is the case for example the first time we start the program)
			return (NULL);
		temp[i] = '\0';										//terminates the str at the last bytes
		if(!buffer)											//if the buffer was never initialised (first time we run the programm) 
			buffer = ft_strdup(temp);						
		else
			buffer = ft_strjoin(buffer, temp);				//if buffer has stored data, the new temp date gets added at the end of buffer
		if (!buffer)										//checks if the malloc function has properly allocated memory in ft_strdup/ft_strjoin
			return (NULL);
	}
	return (buffer);
}