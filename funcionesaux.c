#include "holberton.h"
/**
 * free_list - adds a
 * @head: pointer
 *
 */
void free_list(dir *head)
{
	if (head != NULL)
	{
		free(head->direccion);
		free_list(head->next);
		free(head);
	}
}
/**
 * _strdup - check the code for Holberton School students.
 * @str: string origin
 * Return: pointer s is copy of original
 */

char *_strdup(char *str)
{
	char *s;
	int i, j;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{}
	i++;
	s = malloc(i * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		*(s + j) = *(str + j);

	return (s);
}
/**
 * _strcmp - check the code for Holberton School students.
 * @s1 : pointer
 * @s2 : pointer
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int result = 0;

	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	result = *s1 - *s2;
	return (result);
}
/**
 * delete_spaces - check the code for Holberton School students.
 * @elm_spc: delete spaces
 * @count_words :counter
 * Return: Always 0.
 */
char *delete_spaces(char *elm_spc, int *count_words)
{
	int count = 0;
	char *copia = NULL;
	size_t i = 0;

	for (i = 0; elm_spc[i]; i++)
	{
		if (((elm_spc[i] != ' ' && elm_spc[i] != '\t') || count > 1) &&
		    ((elm_spc[i] != ' ' && elm_spc[i] != '\t') ||
		     (elm_spc[i + 1] != ' ' && elm_spc[i + 1] != '\t' &&
		      elm_spc[i + 1] != '\0')))
			count++;
	}
	count++;
	copia = malloc(sizeof(char) * (count));
	if (copia == NULL)
		return (NULL);
	count = 0;
	for (i = 0; elm_spc[i]; i++)
	{
		if (((elm_spc[i] != ' ' && elm_spc[i] != '\t') || count > 1) &&
		    ((elm_spc[i] != ' ' && elm_spc[i] != '\t') ||
		     (elm_spc[i + 1] != ' ' && elm_spc[i + 1] != '\t' &&
		      elm_spc[i + 1] != '\0')))
		{
			copia[count] = elm_spc[i];
			count++;
		}
	}
	copia[count] = '\0';
	*count_words = count;
	return (copia);
}
/**
 * _selection - function that take over of to select any function
 * @environ:list of vars
 * @test:path
 * @count_cmd:counter commands
 * @source: doble pointer
 * Return:rt
 */
int _selection(char **source, char **environ, dir **test, long int *count_cmd)
{
	built_in comands[] = {{"which", _which},
			      {"help", _help},
			      {"cd", _cd},
			      {"env", _env},
			      {NULL, NULL}};
	int i = 0;
	int rt = 0;

	for (i = 0;  comands[i].comandokey != NULL ; i++)
	{
		if ((_strcmp(source[0], comands[i].comandokey)) == 0)
		{
			rt = comands[i].func(source, environ, test, count_cmd);
			break;
		}
	}
	return (rt);
}
