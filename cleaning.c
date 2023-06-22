#include "monty.h"

/**
 * _not_empty - honestly, idk.
 * @line: idk.
 * 
 * Return: 0 if it's empty, 1 if it's not empty..
 */
size_t _not_empty(char *line)
{
	size_t j;

	for (j = 0; j < strlen(line); j++)
	{
		if (line[j] != ' ' && line[j] != '\t' && line[j] != '\n')
			break;
	}
	if (j == strlen(line) || line[j] == '#')
		return (0); /* empty */
	return (1); /* not empty */
}

/**
 * cleaning_spaces - honestly, idk.
 * @line: char parameter.
 * 
 * Return: data struct.
 */
contents_v cleaning_spaces(char *line)
{
	contents_v data;
	char *tkn;
	size_t j;

	data.op_func = NULL;
	data.value = NULL;
	tkn = strtok(line, " \n\t");
	while (tkn != NULL)
	{
		if (strcmp(tkn, ""))
		{
			data.op_func = tkn;
			break;
		}
		tkn = strtok(NULL, " \n\t");
	}
	if (tkn == NULL)
		return (data);

	tkn = strtok(NULL, " \n\t");
	while (tkn != NULL)
	{
		if (strcmp(tkn, ""))
		{
			for (j = 0; j < strlen(tkn); j++)
			{
				if (!(tkn[j] >= '0' && tkn[j] <= '9'))
					if (tkn[0] != '-')
						break;
			}
			if (j == strlen(tkn))
			{
				if (!strcmp(tkn, "-0"))
					data.value = 0;
				data.value = tkn;
			}
		}
		tkn = strtok(NULL, " \n\t");
	}
	return (data);
}
