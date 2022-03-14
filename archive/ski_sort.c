/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ski_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:33:12 by ski               #+#    #+#             */
/*   Updated: 2022/02/17 13:33:14 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* ************************************************************************** */
void ski_sort(t_data *d)
{
	// bool flag_0_b;  // A EFFACER
	// bool flag_order_a; // A EFFACER
	/* --------------------------------------------------------- */    
	if ((has_less_than_2_elem(&(d->a.head))) || (is_in_order(d->a.head)))
		return ;
	/* --------------------------------------------------------- */

	// BOUCLE-1 (tant que A en DESORDRE) ----------------------------------
	while(!is_in_order(d->a.head))
	{
		// BOUCLE-2 (tant que PAS pret a PUSH-B) --------------------------
		while (!is_ready_push_b(d))
		{
			do_rotation(d);
			do_swap(d);
		}
		// RETOUR BOUCLE-2 ------------------------------------------------

		// test: si A en ordre | alors flag A = true ET sortir boucle
		// test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT
		if (is_in_order(d->a.head))
		{
			// ATTENTION B en ORDRE 	si 	(!)is_in_order(B)
			// ATTENTION B en DESORDRE 	si 	is_in_order(B)
			// if (is_in_order(d->b.head))
			// 	{ft_printf("stack B en DESORDRE\n");} 
			break;
		}
		// PUSH_TO_B 1 fois
		push_to_b(d);    
	}
	// RETOUR BOUCLE-1 ------------------------------------------------

	// sauvegarde REPERE sur grande piece du fond A
	d->tail_ref = d->a.tail;

	// ROT_A: tant que
	//      sommet A < sommet B 
	//      (ET) que B n'est PAS VIDE
	//      (ET) sommet A n-a PAS atteint TAIL_REF
	while (
			(has_1_elem_or_more(&d->b.head))
			&& 
			(d->a.head->val < d->b.head->val) 
			&& 
			(d->a.head != d->tail_ref)
		)
		rotate_a(d);


	// BOUCLE-3 (tant que B n-est PAS VIDE) ----------------------------------
	// while (!(has_0_elem_only(&d->b.head) && is_in_order(d->a.head)))
	while (!(has_0_elem_only(&d->b.head)))
	{		
		while (!is_ready_push_a(d))
		{
			// SWAP_B: si
			// 		[B n est PAS VIDE (ET) sommet B < next B]
			if ((has_2_elem_or_more(&d->b.head)) && (d->b.head->val < d->b.head->next->val))
				swap_b(d);

			// REV_ROT(A): tant que 
			//		[fond A != REPERE (ET) B n est PAS VIDE (ET) fond A > sommet B] 
			//		(OU) 
			//		[fond A != REPERE (ET) B est VIDE ]
			while ((d->a.tail != d->tail_ref) && (
				((has_1_elem_or_more(&d->b.head)) && (d->a.tail->val > d->b.head->val)				)
				|| 
				(has_0_elem_only(&d->b.head))))
				rev_rot_a(d);

			while(
				(has_2_elem_or_more(&d->a.head))
				&&			
				(has_1_elem_or_more(&d->b.head))				
				&&
				(d->a.head != d->tail_ref)
				&&
				(d->a.head->val < d->b.head->val)

				)
				rotate_a(d);
		}

		push_to_a(d);			

	}	
	// RETOUR BOUCLE-3 ------------------------------------------------

	// REV_ROT(A): tant que 
	//		[fond A != REPERE (ET) B n est PAS VIDE (ET) fond A > sommet B] 
	//		(OU) 
	//		[fond A != REPERE (ET) B est VIDE ]
	while ((d->a.tail != d->tail_ref))
		rev_rot_a(d);

	// ----------------------------------------------------------------
	if (FLAG_INFO_RES)
	{
		if (has_0_elem_only(&d->b.head))
			ft_printf("B est vide\n");
		else
			ft_printf("B est PAS VIDE !!! \n");

		if (is_in_order(d->a.head))
			ft_printf("A est en ordre\n");
		else
			ft_printf("A est EN DESORDRE !!!\n");

		ft_printf("Nombre de commande: %d\n", d->cnt_cmd);
		ft_printf("Taille de la stack A: %d\n", ps_size(d->a.head));

	}
}

/* ************************************************************************** */

	// BOUCLE-1 (tant que A en DESORDRE) ----------------------------------
		// BOUCLE-2 (tant que PAS pret a PUSH-B) --------------------------
			// cas_1: boucle tant que head A > fond A | alors rot(A)
			// cas_2: boucle tant que head B < fond B | alors rot(B)
			// si cas_1 et cas_2 | alors rot(2)
			// cas_3: si head A > next A | alors swap(A)
			// cas_4: si head B < next A | alors swap(B)
			// si cas_3 et cas_4 | alors swap(2) 
		// RETOUR BOUCLE-2 ------------------------------------------------
		// test: si A en ordre | alors flag A = true ET sortir boucle
		// test: si A en ordre ET B en DESORDRE | alors afficher AVERTISSEMENT
		// PUSH_TO_B 1 fois
	// RETOUR BOUCLE-1 ------------------------------------------------

	// sauvegarde REPERE sur grande piece du fond A

	// ROT_A: tant que
	//      B n'est PAS VIDE
	//      (ET) sommet A < sommet B 
	//      (ET) sommet A != TAIL_REF

	// BOUCLE-3 (tant que B n-est PAS VIDE) ----------------------------------		
		// SWAP_B: si
		// 		[B n est PAS VIDE (ET) sommet B < next B]

		// REV_ROT(A): tant que 
		//		[fond A != REPERE (ET) B n est PAS VIDE (ET) fond A > sommet B] 
		//		(OU) 
		//		[fond A != REPERE (ET) B est VIDE ]

		// PUSH_TO_A: si
		//		[B n est PAS VIDE (ET) TAIL_REF != fond A (ET)  sommet B > fond A]
		//		(OU)
		//		[B n est pas VIDE (ET) TAIL_REF = fond A]		
	// RETOUR BOUCLE-3 ------------------------------------------------

	// si fond A = REPERE (ET A en DESORDRE) | alors SORTIR + afficher AVERTISSEMENT		
	// test: si B est vide ET A est en ORDRE | alors sortir boucle






	// flag_0_b = has_0_elem_only(&d->b.head);  // A EFFACER
	// flag_order_a = is_in_order(d->a.head); // A EFFACER

	// // BOUCLE-3 (tant que B n-est PAS VIDE) ----------------------------------
	// while (!(flag_0_b && flag_order_a))
	// // while ((has_1_elem_or_more(&d->b.head)) || (!is_in_order(d->a.head)))
	// {		
	// 	// SWAP_B: si
	// 	// 		[B n est PAS VIDE (ET) sommet B < next B]
	// 	if ((has_2_elem_or_more(&d->b.head)) && (d->b.head->val < d->b.head->next->val))
	// 		swap_b(d);

	// 	// REV_ROT(A): tant que 
	// 	//		[fond A != REPERE (ET) B n est PAS VIDE (ET) fond A > sommet B] 
	// 	//		(OU) 
	// 	//		[fond A != REPERE (ET) B est VIDE ]
	// 	if ((d->a.tail != d->tail_ref) && (
	// 		((has_1_elem_or_more(&d->b.head)) && (d->a.tail->val > d->b.head->val)				)
	// 		|| 
	// 		(has_0_elem_only(&d->b.head))))
	// 		rev_rot_a(d);

	// 	// PUSH_TO_A: si
	// 	//		[B n est PAS VIDE (ET) TAIL_REF != fond A (ET)  sommet B > fond A]
	// 	//		(OU)
	// 	//		[B n est PAS VIDE (ET) TAIL_REF = fond A]
	// 	if((has_1_elem_or_more(&d->b.head)) &&(
	// 			((d->a.tail != d->tail_ref) && (d->b.head->val > d->a.tail->val))
	// 			||
	// 			(d->a.tail == d->tail_ref)))
	// 		push_to_a(d);

	// 	flag_0_b = has_0_elem_only(&d->b.head);  // A EFFACER
	// 	flag_order_a = is_in_order(d->a.head); // A EFFACER

	// }	
	// // RETOUR BOUCLE-3 ------------------------------------------------
