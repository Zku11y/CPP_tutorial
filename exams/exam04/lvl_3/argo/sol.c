//this code is already given
//you just need to code the following functions that you can find in argo.c
//parse_int - parse_string - parse_map - parser - argo

//note that if everything is perfect but still there is a segfault in the 9th test just replace <stdlib.h>
//with <malloc.h> don't worry if it doesn't compile in your machine

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>


typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct	pair {
	char	*key;
	json	value;
}	pair;

void	free_json(json j);
int	argo(json *dst, FILE *stream);

int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	if (peek(stream) != EOF)
		printf("unexpected token '%c'\n", peek(stream));
	else
		printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	if (peek(stream) == c)
	{
		(void)getc(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

void	free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break ;
		case STRING:
			free(j.string);
			break ;
		default:
			break ;
	}
}

void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break ;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break ;
		case MAP:
			putchar('{');
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break ;
	}
}
int parser(json *dst, FILE *stream);

// --- YOUR IMPLEMENTATION ---

// 1. Parse Integers
int parse_int(json *dst, FILE *stream) {
    // fscanf is allowed and easiest for integers
    if (fscanf(stream, "%d", &dst->integer) != 1) {
        unexpected(stream);
        return -1;
    }
    dst->type = INTEGER;
    return 1;
}

// 2. Parse Strings
int parse_string(json *dst, FILE *stream) {
    char buffer[4096]; // Static buffer, sufficient for exam scope
    int i = 0;

    if (!expect(stream, '"')) return -1; // Must start with quote

    while (peek(stream) != '"' && peek(stream) != EOF) {
        int c = getc(stream);
        
        if (c == '\\') { // Handle Escape
            c = getc(stream);
        }
        buffer[i++] = c;
    }

    if (!expect(stream, '"')) return -1; // Must end with quote

    buffer[i] = '\0';
    dst->type = STRING;
    // strdup is often not allowed, so we malloc + strcpy
    dst->string = malloc(i + 1);
    if (!dst->string) return -1;
    
    for(int k=0; k<=i; k++) dst->string[k] = buffer[k];
    
    return 1;
}

// 3. Parse Maps (The Hard Part)
int parse_map(json *dst, FILE *stream) {
    dst->type = MAP;
    dst->map.data = NULL;
    dst->map.size = 0;

    if (!expect(stream, '{')) return -1;

    // Check for empty map {}
    while (isspace(peek(stream))) getc(stream); // skip space
    if (accept(stream, '}')) return 1;

    while (1) {
        // 1. Expand the array using realloc
        // Note: realloc(NULL, size) acts like malloc(size)
        struct pair *tmp = realloc(dst->map.data, (dst->map.size + 1) * sizeof(struct pair));
        if (!tmp) return -1;
        dst->map.data = tmp;

        // 2. Parse the Key (which is a string)
        // We parse it into a temp json object first to reuse logic
        json key_obj;
        while (isspace(peek(stream))) getc(stream);
        if (parse_string(&key_obj, stream) == -1) return -1;
        
        // Move the string from temp obj to our pair key
        dst->map.data[dst->map.size].key = key_obj.string;

        // 3. Expect colon
        while (isspace(peek(stream))) getc(stream);
        if (!expect(stream, ':')) return -1;

        // 4. Parse the Value
        // We parse directly into the value slot of the current pair
        while (isspace(peek(stream))) getc(stream);
        if (parser(&dst->map.data[dst->map.size].value, stream) == -1) return -1;

        // Increment size only after successful parse
        dst->map.size++;

        // 5. Check for comma or end
        while (isspace(peek(stream))) getc(stream);
        if (accept(stream, '}')) {
            return 1; // End of map
        }
        if (!expect(stream, ',')) return -1; // Must be comma if not end
    }
}

// 4. The Dispatcher
int parser(json *dst, FILE *stream) {
    while (isspace(peek(stream))) getc(stream);
    
    int c = peek(stream);
    
    if (c == '{')
        return parse_map(dst, stream);
    else if (c == '"')
        return parse_string(dst, stream);
    else if (isdigit(c) || c == '-')
        return parse_int(dst, stream);
    else {
        unexpected(stream);
        return -1;
    }
}

// 5. Entry Point
int argo(json *dst, FILE *stream) {
    return parser(dst, stream);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	json	file;
	if (argo (&file, stream) != 1)
	{
		free_json(file);
		return 1;
	}
	serialize(file);
	printf("\n");
}