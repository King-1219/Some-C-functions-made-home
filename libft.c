#include <stdio.h>
#include <stdlib.h>


size_t ft_strlen(const char *s){
    size_t count = 0;
    while (*s++) count++;
    return count;
}

int ft_atoi(const char *str){
    int sign = 1, ans = 0;
    if (str[0] == '-'){
        sign *= -1;
        str++;
    }
    while (*str){
        ans = ans * 10 + *str - '0';
        str++;
    }
    return ans * sign;
}

int ft_islower(const char c){
    return ('a' <= c  && c <= 'z');
}

int ft_isupper(const char c){
    return ('A' <= c  && c <= 'Z');
}

int ft_isalpha(const char c){
    return (ft_isupper(c) || ft_islower(c));
}

int ft_isascii(const char c){
    return (0 <= c && c <= 127);
}

int ft_isdigit(const char c){
    return ('0' <= c && c <= '9');
}

int ft_isspace(const char c){
    return (c == ' ');
}

char ft_tolower(char c){
    if ('A' <= c && c <= 'Z') c += 32;
    return c;
}

char ft_toupper(char c){
    if ('a' <= c && c <= 'z') c -= 32;
    return c;
}

static size_t ft_intlen(int n){
    int len = 0;
    if (n < 0){
        len++;
        n *= -1;
    }
    while (n > 0){
        n /= 10;
        len++;
    }
    return len;
}

char *ft_itoa(int n){
    size_t len = ft_intlen(n);
    char *str = malloc(sizeof(char) * len + 1);
    str[len] = '\0';
    if (n < 0){
        str[0] = '-';
        n *= -1;
        len--;
    }
    while (n > 0){
        str[len] = n % 10  + 48;
        n /= 10;
        len--;
    }
    return str;
}

static size_t ft_count_words(const char *str, const char c){
    size_t count = 1;
    while (*str){
        if (*str++ == c) count++;
    }
    return count;
}

static void ft_write_words(const char *str, const char c, int nb_words, char **ans){
    int i = -1, j = 0, k;
    while (++i < nb_words){
        k = 0;
        while (str[j] == c) j++;
        while (str[j] && str[j] != c){
            ans[i][k++] = str[j++];
        }
        ans[i][k] = '\0';
    }
}

static void ft_malloc_words(const char *str, const char c, int nb_words, char **ans){
    int i = -1, j = 0, k;
    while (++i < nb_words){
        k = 0;
        while (str[j] == c) j++;
        while (str[j] && str[j] != c){
            j++;
            k++;
        }
        ans[i] = (char *)malloc(sizeof(char) * (k + 1));
    }
}

char **ft_split(const char *str, const char c){
    size_t nb_words = ft_count_words(str, c);
    char **ans = malloc(sizeof(char *) * (nb_words + 1));
    ft_malloc_words(str, c, nb_words, ans);
    ft_write_words(str, c, nb_words, ans);
    ans[nb_words] = 0;
    return ans;
}

char *ft_substr(const char *str, const int start, const int num){
    char *ans = malloc(sizeof(char) * num + 1);
    int i = start;
    while (i < start + num && str[i]){
        *(ans+i-start) = *(str+i);
        i++; 
    }
    *(ans+num) = '\0';
    return ans;
}

int main(){
    char *s = ft_substr("Heyksdo", 4, 3);
    printf("%s", s);
    return 0;
}