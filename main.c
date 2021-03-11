#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
int	main(void)
{
	int			i = 0;
	char		*cmp1 = "string for cmp\0";
	char		*cmp2 = "string for cmp\0";
	const char	*src_cpy = "string for cpy";
	char		*dst_cpy1;
	char		*dst_cpy2;
	const char	*src_len = "string for len";
	const char	*src_dup = "string for dub";
	char		*dst_dup;
	char		*dst_dup2;
	int			wfd = -5;
	const char	*wstr = "string for write";
	int			wlen = 16;
	int			rfd = -5;
	char		rlen = 18;
	char		rstr[100] = {0};
	const char	*error_str = "errno";
	rfd = open("main.c", O_RDONLY);
	dst_cpy1 = (char*)malloc(sizeof(char) * (strlen(src_cpy) + 1));
	dst_cpy2 = (char*)malloc(sizeof(char) * (strlen(src_cpy) + 1));
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("========strcmp=======\n");
	printf("strcmp  : %d\n", strcmp(cmp1, cmp2));
	printf("ft_strcmp: %d\n", ft_strcmp(cmp1, cmp2));
	printf("========strcpy=======\n");
	strcpy(dst_cpy1, src_cpy);
	printf("strcpy  : s: %s || d: %s\n", src_cpy, dst_cpy1);
	ft_strcpy(dst_cpy2, src_cpy);
	printf("ft_strcpy: s: %s || d: %s\n", src_cpy, dst_cpy2);
	printf("========strlen=======\n");
	printf("strlen  : %lu\n", strlen(src_len));
	printf("ft_strlen: %lu\n", ft_strlen(src_len));
	printf("========strdup=======\n");
	dst_dup = strdup(src_dup);
	printf("strdup  : %s\n", dst_dup);
	dst_dup2 = ft_strdup(src_dup);
	printf("ft_strdup: %s\n", dst_dup2);
	printf("========write========\n");
	errno = 0;
	printf("\nwrite return  : %ld\n", write(wfd, wstr, wlen));
	perror(error_str);
	errno = 0;
	printf("\nft_write return: %ld\n", ft_write(wfd, wstr, wlen));
	perror(error_str);
	printf("========read=========\n");
	errno = 0;
	printf("read return  : %ld\n", read(rfd, rstr, rlen));
	write(1, rstr, rlen);
	write(1, "\n", 1);
	perror(error_str);
	close(rfd);
	while (i < 101)
		rstr[i++] = 0;
	rfd = open("main.c", O_RDONLY);
	errno = 0;
	printf("ft_read return: %ld\n", ft_read(rfd, rstr, rlen));
	write(1, rstr, rlen);
	write(1, "\n", 1);
	perror(error_str);
	errno = 0;
	close(rfd);
	free(dst_cpy1);
	free(dst_cpy2);
	free(dst_dup);
	free(dst_dup2);
	return (0);
}