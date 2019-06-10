# define MANDELBROT 2
# define JULIA 4
# define BURNINGSHIP 8

////////////////// Typedefs //////////////////

typedef struct	s_complex
{
	double	im;
	double	re;
}		t_complex;

typedef struct	s_fract
{
	float		maxre;
	float		minre;
	float		maxim;
	float		minim;
	float		c_im;
	float		c_re;
	float		z_re;
	float		z_re2;
	float		z_im;
	float		z_im2;
	float		re_factor;
	float		im_factor;
	unsigned	maxiterations;
	unsigned int	test;
	int			n;
	int			x;
	int			y;
	float		scale;
	int			palette;
	int			psychedelic;
	int			mask;
}		t_fract;

////////////////// Prototypes //////////////////

inline double	ft_abs(double nb);
inline int		ft_palette_one(int n, int max, bool p);
inline int		ft_palette_two(int n, int max, bool p);
inline int		ft_palette_three(int n, int max, bool p);
inline int		ft_palette_four(int n, int max, bool p);
inline int		ft_palette_five(int n, int max, bool p);
inline int		ft_palette_tree(int n, int max, int palette, bool psychedelic);
inline double	ft_fractals_tree(t_fract *s, const int mask, const char w, const float juliax, const float juliay);

////////////////// Fonctions maths //////////////////

inline double	ft_abs(double nb)
{
	return (nb < 0 ? -nb : nb);
}

////////////////// Palettes de couleurs //////////////////

inline int		ft_palette_one(int n, int max, bool p)
{
	const int	tab[10] = {0x00ff00, 0x20dd20, 0x40bb20, 0x609020,
				0x906020, 0xbb4020, 0xff2020, 0xff9020,
				0xffdd20, 0xffff90};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 10]);
}

inline int		ft_palette_two(int n, int max, bool p)
{
	const int	tab[16] = {0x000000, 0xffffff, 0x050505, 0xfefefe,
				0x101010, 0xeeeeee, 0x151515, 0xdedede,
				0x202020, 0xdddddd, 0x252525, 0xcdcdcd,
				0x303030, 0xcccccc, 0x353535, 0xbcbcbc};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 16]);
}

inline int		ft_palette_three(int n, int max, bool p)
{
	const int	tab[12] = {0x0000ff, 0x1020ff, 0x2040ff, 0x3060ff,
				0x4080ff, 0x50aaff, 0x60ccff, 0x70eeff,
				0x80ffff, 0xddffaa, 0xeebb90, 0xff8080};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 12]);
}

inline int		ft_palette_four(int n, int max, bool p)
{
	const int	tab[10] = {0xff0000, 0x00ff00, 0x0000ff, 0xffff00,
				0xff00ff, 0x00ffff, 0xffdd00, 0x00ffdd, 
				0xdd00ff, 0xc3f23f};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 10]);
}

inline int		ft_palette_five(int n, int max, bool p)
{
	const int tab[7] = {0x0000ff, 0x3399ff, 0x00ffff, 0x00ff00,
			0xffff00, 0x82004b, 0xe22b8a};

	if (n == max)
		return (0);
	return (tab[(n + (p ? max : 0)) % 7]);
}

////////////////// Arbres de conditions //////////////////

inline double	ft_fractals_tree(t_fract *s, const int mask, const char w, const float juliax, const float juliay)
{
	float	tx;
	float	ty;

	if (mask == MANDELBROT)
	{
		tx = (s->z_re + s->z_re) * s->z_im;
		ty = s->z_re2 - s->z_im2;
		return ((w == 'x') ? (tx + s->c_im) : ty + s->c_re);
	}
	else if (mask == JULIA)
	{
		tx = ((s->z_re + s->z_re)) * s->z_im;
		ty = s->z_re2 - s->z_im2;
		return ((w == 'x') ? tx + juliax : ty + juliay);
	}
	else if (mask == BURNINGSHIP)
	{
		tx = ft_abs(s->z_re * s->z_im);
		tx += tx;
		ty = s->z_re2 - s->z_im2;
		return ((w == 'x') ? -tx + s->c_im : ty + s->c_re);
	}
	else
		return (0);
}

inline int		ft_palette_tree(int n, int max, int palette, bool psychedelic)
{
	if (palette == 0)
		return (ft_palette_one(n, max, psychedelic));
	else if (palette == 1)
		return (ft_palette_two(n, max, psychedelic));
	else if (palette == 2)
		return (ft_palette_three(n, max, psychedelic));
	else if (palette == 3)
		return (ft_palette_four(n, max, psychedelic));
	else if (palette == 4)
		return (ft_palette_five(n, max, psychedelic));
	else
		return (0);
}

# define ITER do {\
	s.z_re2 = s.z_re * s.z_re;\
	s.z_im2 = s.z_im * s.z_im;\
	if (s.z_re2 + s.z_im2 > 4)\
	{\
		buff[((s.y - 1) * wdt + s.x)] = ft_palette_tree(s.n, s.maxiterations, palette, p);\
		return ;\
	}\
	s.z_im = ft_fractals_tree(&s, mask, 'x', julia_x, julia_x);\
	s.z_re = ft_fractals_tree(&s, mask, 'y', julia_x, julia_y);\
	s.n++;\
}while (0);

__kernel void fractol(__global int *buff, int wdt, int hgt, t_fract s, int palette, int p, int mask, float julia_x, float julia_y)
{
	int	i;

	i = s.maxiterations & 15;
	s.x = get_global_id(1);
	s.y = get_global_id(0);
	s.n = 0;
	s.maxim = s.minim + (s.maxre - s.minre) * hgt / wdt;
	s.re_factor = (s.maxre - s.minre) / wdt;
	s.im_factor = (s.maxim - s.minim) / hgt;
	s.c_im = s.maxim - s.y * s.im_factor;
	s.c_re = s.minre + s.x * s.re_factor;
	s.z_re = s.c_re;
	s.z_im = s.c_im;
	while (s.n < i)
		ITER
	while (s.n < (int)s.maxiterations)
	{
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
		ITER
	}
	buff[((s.y - 1) * wdt + s.x)] = 0;
}
