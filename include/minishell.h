/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:48:04 by ybesbes           #+#    #+#             */
/*   Updated: 2021/10/31 17:09:54 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <../libft/libft.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

extern int g_shell_status;

typedef struct  s_env
{
	char *var;
	char *name;
	char *value;
	struct s_env *next;
} 				t_env;

typedef struct s_command
{
	char	*com;
	char	*args;
	int		out_file_num;
	char 	**outputfiles;
	int		in_file_num;
	char	**inputfiles;
	int		out_file_app_num;
	char	**output_files_append;
	int		expected_words_num;
	char 	**read_from_shell;
}				t_command;

typedef struct s_shellinfo
{
	t_env	*env;
	int		execute;
	int		*old_pipe[2];
	int		*previous;
	int		coming;

}				t_shellinfo;

char **create_tab(t_command com, t_shellinfo shell);
int execute_cmd(t_command com, t_shellinfo shell);
int	char_numb(char *str, char c, int two);
int	check_syntax_errors(char *str);
char **read_from_input(char *str);
void pipe_cmd(t_command com, t_shellinfo shell);
int ft_pwd(void);
int ft_exit(void);
int is_builtin(char *str);
int is_a_real_builtin(char *str);
t_command get_cmd(char *command);
void parse_cmd(char *command, t_command *com_struct);
void ft_free_cmd(t_command *com);
char **get_paths();
char *find_cmd_path(char *cmd);
void ft_skip_quotes(char *str, int *i);
char			**ft_mini_split(char *s, char c);
void		*mini_leak(char **ptr, int words);
void ft_free_tab(char **str);
int quotes_enum(char *str);
int		is_it_between_quotes(char *str, int pos);
void	ft_delete_quotes(char *com);
int		is_it_between_simple_quotes(char *str, int pos);
int		ft_mini_count(char *s, char c);
int handle_single_cmd(char* cmd, char **env);
int ft_cd(char **dir);
int ft_echo(char **arg);
int ft_env(t_env *env);
int	ft_infile(t_command com, int dupIt);
void init_env(t_env **env_list, char **env);
int ft_outfile(t_command com, int dupIt);
int ft_outfile_append(t_command com, int dupIt);
void ft_read_from_shell(t_command com, int dupIt);
int execute_input_output(t_command com);
char *get_name_env(char *s);
int ft_export(t_env *env, char **arg);
void add_env(t_env **env, char *str);
char *get_value(char *s);
int ft_unset(t_env **env_list, char **list_to_delete);
void delete_env(t_env **env_list, char *to_delete);
int is_new_env(char *s);
void handle_ctrl_c();
void handle_ctrl_d();
int exists(char *s, t_env *env, t_env **new_env);
int is_valid_ident(char *s);
void handle_ctrl_backslash();
int ft_strcompare(char *str1, char *str2);
char *getenv_value_from_list(t_shellinfo shell, char *env);
char *substitute_env_var(t_shellinfo shell, char *com);
void ft_swap(t_env *env1, t_env *env2);
int ft_sorted(t_env *list);
void ft_sort(t_env *list);
void heredoc_helper(char *str, int dupit);
int without_arg(t_env *env);
char *to_lowercase(char *s1);
void heredoc_helper(char *str, int dupit);
char *dollar_beween_quotes(char *com, char **str, int char_to_extract, int char_to_add);
int caculate_char_to_add(char *com, char **str);




#endif