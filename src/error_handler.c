/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arch <arch@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:13:16 by arch              #+#    #+#             */
/*   Updated: 2024/06/08 12:35:49 by arch             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/so_long.h"

// void handle_error(int error_code, const char *custom_msg) {
//     // if (error_code >= 1 && error_code < sizeof(error_messages) / sizeof(error_messages[0])) {
//     if (error_code >= 1) {
//         fprintf(stderr, "Error [%d]: %s - %s\n", error_code, error_messages[error_code], custom_msg);
//     } else {
//         fprintf(stderr, "Unknown error code: %d\n", error_code);
//     }

//     if (errno != 0) {
//         perror("System error");
//     } else {
//         fprintf(stderr, "%s\n", strerror(error_code));
//     }
//     exit(EXIT_FAILURE);
// }