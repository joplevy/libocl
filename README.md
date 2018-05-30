# libocl

Première chose que j'ai fait quand j'ai dû utiliser openCL pour faire des calculs sur carte graphique. En écrivant cette librairie, j'ai appris a utiliser openCL en meme temp que je me facilitait la tâche por les projets a venir.

voici un exemple d'utilisation :

```
size_t	pws[2];
pws[0] = WIDTH;
pws[1] = HEIGHT;

ocl_new_prog("./src/mon_fichier.cl", 0x100000 , &(sauvegarde_prog))
// definis un nouveau programme openCLet le compile, la taille maximum du fichier, et sauvegarde le programme sur le pointeur donné


ocl_new_kernel(&(sauvegarde_prog), 4, pws, "norowowowd", "mon_kernel"\
		, WIDTH * HEIGHT * sizeof(int), mlx.p, sizeof(cl_int2), &(mlx.map->size),\
		mlx.map->size.x * mlx.map->size.y + 1, mlx.map->cl_map, sizeof(t_player),\
		&(mlx.player), 2);    
// definis le kernel (fonction openCL) à lancer ainsi que toutes se variable (plus d'info sur le va_arg dans le libocl.h)
// pws (public work size) est le nombre de fois que le kernel va etre lancer simultanément (en foncion de la taille de la carte graphique)
// par exemple le pws definis ci dessus lance le programme autant de foi que le nombre de pixels qu'on a dans la fenette en question.
// en opencl nous recuperons 2 variables qui vont correspondre a la coordonée d'un pixel dans la fenetre avec les 2 lignes suivantes

size_t x = get_global_id(0);
size_t y = get_global_id(1);


ocl_enqueue_kernel(&(sauvegarde_prog)), "mon_kernel");
// cette fonction execute le kernel, qui va lire et ecrire sur les variables définis préalablement
```
