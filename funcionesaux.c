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
	int i = 0;

	for (i = 0; elm_spc[i]; i++)
	{
		if ((elm_spc[i] != ' ' || count > 1) &&
		    (elm_spc[i] != ' ' || (elm_spc[i + 1] != ' '
					   && elm_spc[i + 1] != '\0')))
			count++;
	}
	count++;
	copia = malloc(sizeof(char) * (count));
	if (copia == NULL)
		return (NULL);
	count = 0;
	for (i = 0; elm_spc[i]; i++)
	{
		if ((elm_spc[i] != ' ' || count > 1) &&
		    (elm_spc[i] != ' ' || (elm_spc[i + 1] != ' ' &&
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
 * @source: doble pointer
 * Return: Always 0.
 */
int _selection(char **source)
{
	built_in comands[] = {{"exit", _exit_},
			      {"which", _which},
			      {"help", _help},
			      {"cd", _cd},
			      {NULL, NULL}};

	int i = 0;
	int j = 0;
	int resultado = 0;
	int strc = 0;

	for (i = 0; comands[i].comandokey; i++)
	{
		printf("%s\n", comands[i].comandokey);
		printf("%s\n", source[0]);
		/*for (j = 0; *(source[i] + j) != '\0'; j++)
		{
			if (*(source[i] + j) == comands[i].comandokey[j])
				resultado = 1;
			else
				resultado = 0;
			printf("%s : %d\n", comands[i].comandokey, resultado);
			}*/
		printf("\n");
		strc = (strcmp(source[i], comands[i].comandokey));
		printf("%d\n", strc);
		if ((strcmp(source[i], comands[i].comandokey)) == 0)
		{
			printf("entro al if\n");
			comands[i].func(source);
			break;
		}
	}
	return (0);
}
