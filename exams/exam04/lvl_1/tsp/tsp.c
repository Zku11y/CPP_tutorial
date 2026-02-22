//the code is already given you just need to write the following functions:
//tsp - calculate_path_length - swap - permute

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


 
#include <errno.h>
#include <math.h>
#include <float.h>

float    distance(float a[2], float b[2])
{
    return sqrtf((b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]));
}

void swap(int *a, int *b){
  if(a == b) return;
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

float calculate_path_length(float (*array)[2], int *used, ssize_t size){
  float dst = 0.0f;
  for(int i = 0; used[i + 1]; i++)
    dst += distance(array[used[i]], array[used[i + 1]]);

  dst += distance(array[used[size - 1]], array[used[0]]);
  return dst;
}

void permute(float (*array)[2], ssize_t size, int *used, float *min_dst, int index){
   if(index == size){
    float dst = calculate_path_length(array, used);
    if(dst < *min_dst) *min_dst = dst;
    return;
  }

  for(int i = 0; i < size; i++){
    swap(&used[index], &used[i]);
    permute(array, size, used, min_dst, index + 1);
    swap(&used[index], &used[i]);
  }
}

float tsp(float (*array)[2], ssize_t size){
  float *used = calloc(size, sizeof(int));
  for(int i = 0; i < size; i++)
    used[i] = i;
  float min_dst;
  permute();
  free(used);
}

ssize_t    file_size(FILE *file)
{
    char    *buffer = NULL;
    size_t    n = 0;
    ssize_t ret;

    errno = 0;

    for (ret = 0; getline(&buffer, &n, file) != -1; ret++);

    free(buffer);
    if (errno || fseek(file, 0, SEEK_SET))
        return -1;
    return ret;
}

int        retrieve_file(float (*array)[2], FILE *file)
{
    int tmp;
    for (size_t i = 0; (tmp = fscanf(file, "%f, %f\n", array[i] + 0, array[i] + 1)) != EOF; i++)
        if (tmp != 2)
        {
            errno = EINVAL;
            return -1;
        }
    if (ferror(file))
        return -1;
    return 0;
}

int        main(int ac, char **av)
{
    char *filename = "stdin";
    FILE *file = stdin;
    if (ac > 1)
    {
        filename = av[1];
        file = fopen(filename, "r");
    }

    if (!file)
    {
        fprintf(stderr, "Error opening %s: %m\n", filename);
        return 1;
    }

    ssize_t size = file_size(file);
    if (size == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", filename);
        fclose(file);
        return 1;
    }

    float (*array)[2] = calloc(size, sizeof (float [2]));
    if (!array)
    {
        fprintf(stderr, "Error: %m\n");
        fclose(file);
        return 1;
    }

    if (retrieve_file(array, file) == -1)
    {
        fprintf(stderr, "Error reading %s: %m\n", av[1]);
        fclose(file);
        free(array);
        return 1;
    }
    if (ac > 1)
        fclose(file);

    printf("%.2f\n", tsp(array, size));
    free(array);
}
