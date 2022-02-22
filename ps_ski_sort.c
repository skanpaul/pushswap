/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ski_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void ps_ski_sort(t_data *d)
{
    bool a_in_order; // 0: NOT in order - 1: IN-ORDER
    bool b_in_order; // 0: NOT in order - 1: IN-ORDER

    /* --------------------------------------------------------- */
    a_in_order = false;
    b_in_order = false;
    /* --------------------------------------------------------- */    
    if ((has_less_than_2_elem(&(d->head_a))) || (is_in_order(d->head_a)))
        return ;
    /* --------------------------------------------------------- */

    // si A en ORDRE ET B est VIDE | alors sortir du programme

    // BOUCLE-1 (tant que A en DESORDRE) ----------------------------------
    while(!is_in_order(d->head_a))
    {
        // faire ROTATION autant que necessaire
        // do_rotation(d);

        // test: si A en ordre | alors flag A = true ET sortir boucle
        // test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT
        
        // faire SWAP si necessaire
        // do_swap(d);

        // test: si A en ordre | alors flag A = true ET sortir boucle
        // test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT
        
        // cas_1: boucle tant que head A > fond A | alors rot(A)
        // cas_2: boucle tant que head B < fond B | alors rot(B)
        // si cas_1 et cas_2 | alors rot(2) 

        // test: si A en ordre | alors flag A = true ET sortir boucle
        // test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT

        // PUSH_TO_B 1 fois

        // RETOUR_BOUCLE
    }
    // --------------------------------------------------------------
}




 // si A en ORDRE ET B est VIDE | alors sortir du programme

    // BOUCLE-1 (tant que A en DESORDRE) ----------------------------------

        // cas_1: boucle tant que head A > fond A | alors rot(A)
        // cas_2: boucle tant que head B < fond B | alors rot(B)
        // si cas_1 et cas_2 | alors rot(2) 

        // test: si A en ordre | alors flag A = true ET sortir boucle
        // test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT

        // cas_3: si head A > next A | alors swap(A)
        // cas_4: si head B < next A | alors swap(B)
        // si cas_3 et cas_4 | alors swap(2) 

        // test: si A en ordre | alors flag A = true ET sortir boucle
        // test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT
        
        // cas_1: boucle tant que head A > fond A | alors rot(A)
        // cas_2: boucle tant que head B < fond B | alors rot(B)
        // si cas_1 et cas_2 | alors rot(2) 

        // test: si A en ordre | alors flag A = true ET sortir boucle
        // test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT

        // PUSH_TO_B 1 fois

        // RETOUR_BOUCLE
    // --------------------------------------------------------------

    // si A en ORDRE ET B est VIDE | alors sortir du programme   

    // sauvegarde REPERE sur grande piece du fond A

    // tant que sommet A < sommet B (ET que B n'est PAS VIDE)| alors rot(A)

    // BOUCLE (tant que B n'est PAS VIDE) ---------------------------    

        // tant que sommet B > fond A (ET que B n est PAS VIDE)| alors PUSH_TO_A

        // test: si B est vide ET A est en ORDRE | alors sortir boucle

        // tant que (fond A > sommet B OU B est VIDE) ET (fond A != REPERE) | alors rev_rot(A)
        
        // si fond A = REPERE (ET A en DESORDRE) | alors SORTIR + afficher AVERTISSEMENT

        // RETOUR BOUCLE
    // --------------------------------------------------------------
