/*

Copyright (c) 2005-2008, Simon Howard

Permission to use, copy, modify, and/or distribute this software 
for any purpose with or without fee is hereby granted, provided 
that the above copyright notice and this permission notice appear 
in all copies. 

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL 
WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE 
AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR 
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM 
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, 
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN      
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

 */

#include "mercury_list.h"

#include <stdlib.h>

/* A doubly-linked list */

struct hg_list_entry {
	hg_list_value_t data;
	hg_list_entry_t *prev;
	hg_list_entry_t *next;
};

void hg_list_free(hg_list_entry_t *list)
{
	hg_list_entry_t *entry;

	/* Iterate over each entry, freeing each list entry, until the
	 * end is reached */

	entry = list;

	while (entry != NULL) {
		hg_list_entry_t *next;
	   
		next = entry->next;

		free(entry);

		entry = next;
	}
}

hg_list_entry_t *hg_list_prepend(hg_list_entry_t **list, hg_list_value_t data)
{
	hg_list_entry_t *newentry;

	/* Create new entry */

	newentry = (hg_list_entry_t*) malloc(sizeof(hg_list_entry_t));

	if (newentry == NULL) {
		return NULL;
	}
	
	newentry->data = data;

	/* Hook into the list start */

	if (*list != NULL) {
		(*list)->prev = newentry;
	}
	newentry->prev = NULL;
	newentry->next = *list;
	*list = newentry;

	return newentry;
}

hg_list_entry_t *hg_list_append(hg_list_entry_t **list, hg_list_value_t data)
{
	hg_list_entry_t *rover;
	hg_list_entry_t *newentry;

	/* Create new list entry */

	newentry = (hg_list_entry_t*) malloc(sizeof(hg_list_entry_t));

	if (newentry == NULL) {
		return NULL;
	}
	
	newentry->data = data;
	newentry->next = NULL;
	
	/* Hooking into the list is different if the list is empty */

	if (*list == NULL) {

		/* Create the start of the list */

		*list = newentry;
		newentry->prev = NULL;

	} else {

		/* Find the end of list */

		for (rover=*list; rover->next != NULL; rover = rover->next);

		/* Add to the end of list */

		newentry->prev = rover;
		rover->next = newentry;
	}

	return newentry;
}

hg_list_value_t hg_list_data(hg_list_entry_t *listentry)
{
	return listentry->data;
}

hg_list_entry_t *hg_list_prev(hg_list_entry_t *listentry)
{
	return listentry->prev;
}

hg_list_entry_t *hg_list_next(hg_list_entry_t *listentry)
{
	return listentry->next;
}

hg_list_entry_t *hg_list_nth_entry(hg_list_entry_t *list, unsigned int n)
{
	hg_list_entry_t *entry;
	unsigned int i;

	/* Iterate through n list entries to reach the desired entry.
	 * Make sure we do not reach the end of the list. */

	entry = list;

	for (i=0; i<n; ++i) {

		if (entry == NULL) {
			return NULL;
		}
		entry = entry->next;
	}

	return entry;
}

hg_list_value_t hg_list_nth_data(hg_list_entry_t *list, unsigned int n)
{
	hg_list_entry_t *entry;

	/* Find the specified entry */

	entry = hg_list_nth_entry(list, n);

	/* If out of range, return NULL, otherwise return the data */

	if (entry == NULL) {
		return HG_LIST_NULL;
	} else {
		return entry->data;
	}
}

unsigned int hg_list_length(hg_list_entry_t *list)
{
	hg_list_entry_t *entry;
	unsigned int length;

	length = 0;
	entry = list;

	while (entry != NULL) {

		/* Count the number of entries */

		++length;

		entry = entry->next;
	}

	return length;
}

hg_list_value_t *hg_list_to_array(hg_list_entry_t *list)
{
	hg_list_entry_t *rover;
	hg_list_value_t *array;
	unsigned int length;
	unsigned int i;

	/* Allocate an array equal in size to the list length */

	length = hg_list_length(list);

	array = (hg_list_value_t*) malloc(sizeof(hg_list_value_t) * length);

	if (array == NULL) {
		return NULL;
	}

	/* Add all entries to the array */

	rover = list;

	for (i=0; i<length; ++i) {

		/* Add this node's data */

		array[i] = rover->data;

		/* Jump to the next list node */

		rover = rover->next;
	}

	return array;
}

int hg_list_remove_entry(hg_list_entry_t **list, hg_list_entry_t *entry)
{
	/* If the list is empty, or entry is NULL, always fail */

	if (*list == NULL || entry == NULL) {
		return 0;
	}
	
	/* Action to take is different if the entry is the first in the list */

	if (entry->prev == NULL) {

		/* Unlink the first entry and update the starting pointer */

		*list = entry->next;

		/* Update the second entry's prev pointer, if there is a second
		 * entry */

		if (entry->next != NULL) {
			entry->next->prev = NULL;
		}

	} else {

		/* This is not the first in the list, so we must have a 
		 * previous entry.  Update its 'next' pointer to the new 
		 * value */

		entry->prev->next = entry->next;

		/* If there is an entry following this one, update its 'prev'
		 * pointer to the new value */

		if (entry->next != NULL) {
			entry->next->prev = entry->prev;
		}
	}

	/* Free the list entry */

	free(entry);

	/* Operation successful */

	return 1;
}

unsigned int hg_list_remove_data(hg_list_entry_t **list, hg_list_equal_func_t callback,
                              hg_list_value_t data)
{
	unsigned int entries_removed;
	hg_list_entry_t *rover;
	hg_list_entry_t *next;

	entries_removed = 0;

	/* Iterate over the entries in the list */

	rover = *list;

	while (rover != NULL) {

		next = rover->next;

		if (callback(rover->data, data)) {

			/* This data needs to be removed.  Unlink this entry
			 * from the list. */

			if (rover->prev == NULL) {

				/* This is the first entry in the list */

				*list = rover->next;
			} else {

				/* Point the previous entry at its new
				 * location */

				rover->prev->next = rover->next;
			}

			if (rover->next != NULL) {
				rover->next->prev = rover->prev;
			}

			/* Free the entry */

			free(rover);

			++entries_removed;
		}

		/* Advance to the next list entry */

		rover = next;
	}

	return entries_removed;
}

/* Function used internally for sorting.  Returns the last entry in the
 * new sorted list */

static hg_list_entry_t *list_sort_internal(hg_list_entry_t **list,
                                     hg_list_compare_func_t compare_func)
{
	hg_list_entry_t *pivot;
	hg_list_entry_t *rover;
	hg_list_entry_t *less_list, *more_list;
	hg_list_entry_t *less_list_end, *more_list_end;
	
	/* If there are less than two entries in this list, it is
	 * already sorted */

	if (*list == NULL || (*list)->next == NULL) {
		return *list;
	}

	/* The first entry is the pivot */

	pivot = *list;

	/* Iterate over the list, starting from the second entry.  Sort
	 * all entries into the less and more lists based on comparisons
	 * with the pivot */

	less_list = NULL;
	more_list = NULL;
	rover = (*list)->next;

	while (rover != NULL) {
		hg_list_entry_t *next = rover->next;

		if (compare_func(rover->data, pivot->data) < 0) {

			/* Place this in the less list */

			rover->prev = NULL;
			rover->next = less_list;
			if (less_list != NULL) {
				less_list->prev = rover;
			}
			less_list = rover;

		} else {

			/* Place this in the more list */

			rover->prev = NULL;
			rover->next = more_list;
			if (more_list != NULL) {
				more_list->prev = rover;
			}
			more_list = rover;
		}

		rover = next;
	}

	/* Sort the sublists recursively */

	less_list_end = list_sort_internal(&less_list, compare_func);
	more_list_end = list_sort_internal(&more_list, compare_func);

	/* Create the new list starting from the less list */

	*list = less_list;

	/* Append the pivot to the end of the less list.  If the less list
	 * was empty, start from the pivot */

	if (less_list == NULL) {
		pivot->prev = NULL;
		*list = pivot;
	} else {
		pivot->prev = less_list_end;
		less_list_end->next = pivot;
	}

	/* Append the more list after the pivot */

	pivot->next = more_list;
	if (more_list != NULL) {
		more_list->prev = pivot;
	}

	/* Work out what the last entry in the list is.  If the more list was 
	 * empty, the pivot was the last entry.  Otherwise, the end of the 
	 * more list is the end of the total list. */

	if (more_list == NULL) {
		return pivot;
	} else {
		return more_list_end;
	}
}

void hg_list_sort(hg_list_entry_t **list, hg_list_compare_func_t compare_func)
{
	list_sort_internal(list, compare_func);
}

hg_list_entry_t *hg_list_find_data(hg_list_entry_t *list,
                          hg_list_equal_func_t callback,
                          hg_list_value_t data)
{
	hg_list_entry_t *rover;

	/* Iterate over entries in the list until the data is found */

	for (rover=list; rover != NULL; rover=rover->next) {
		if (callback(rover->data, data) != 0) {
			return rover;
		}
	}
	
	/* Not found */

	return NULL;
}

void hg_list_iterate(hg_list_entry_t **list, hg_list_iter_t *iter)
{
	/* Start iterating from the beginning of the list. */

	iter->prev_next = list;

	/* We have not yet read the first item. */

	iter->current = NULL;
}

int hg_list_iter_has_more(hg_list_iter_t *iter)
{
	if (iter->current == NULL || iter->current != *iter->prev_next) {

		/* Either we have not read the first entry, the current
		 * item was removed or we have reached the end of the
		 * list.  Use prev_next to determine if we have a next
		 * value to iterate over. */

		return *iter->prev_next != NULL;

	} else {
		/* The current entry as not been deleted since the last 
		 * call to list_iter_next: there is a next entry if 
		 * current->next is not NULL */

		return iter->current->next != NULL;
	}
}

hg_list_value_t hg_list_iter_next(hg_list_iter_t *iter)
{
	if (iter->current == NULL || iter->current != *iter->prev_next) {

		/* Either we are reading the first entry, we have reached
		 * the end of the list, or the previous entry was removed.
		 * Get the next entry with iter->prev_next. */

		iter->current = *iter->prev_next;

	} else {

		/* Last value returned from list_iter_next was not deleted.
		 * Advance to the next entry. */

		iter->prev_next = &iter->current->next;
		iter->current = iter->current->next;
	}
	
	/* Have we reached the end of the list? */

	if (iter->current == NULL) {
		return HG_LIST_NULL;
	} else {
		return iter->current->data;
	}
}

void hg_list_iter_remove(hg_list_iter_t *iter)
{
	if (iter->current == NULL || iter->current != *iter->prev_next) {

		/* Either we have not yet read the first item, we have 
		 * reached the end of the list, or we have already removed
		 * the current value.  Either way, do nothing. */

	} else {
		
		/* Remove the current entry */

		*iter->prev_next = iter->current->next;

		if (iter->current->next != NULL) {
			iter->current->next->prev = iter->current->prev;
		}

		free(iter->current);
		iter->current = NULL;
	}
}

