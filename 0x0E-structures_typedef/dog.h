#ifndef KAMAL_H
#define KAMAL_H

/**
 * struct k - a k struct
 * @kname: k's kname
 * @kage: k's kage
 * @kowner: owner's kname
 *
 * Description: just a lone k struct in a big kitty world
 */
struct k
{
	char *kname;
	float kage;
	char *kowner;
};

typedef struct k k_t;

void init_k(struct k *d, char *kname, float kage, char *kowner);
void print_k(struct k *d);
k_t *new_k(char *kname, float kage, char *kowner);
void free_k(k_t *d);

#endif
