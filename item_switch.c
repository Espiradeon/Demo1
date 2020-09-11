#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{

    char *inventory[]= {"id_001", "id_002", "empty", "id_003", "empty", "id_004"};
    char *equipped[] = {"NEW_SLOT"};    // NEW_SLOT is just to highlight what would
    char *item_switch[] = {"None"};     // otherwise be id_005 more clearly.

    // item_switch is used a placeholder to duplicate current
    // equipped item, which will later be removed.
    for (int i = 0; i < 1; i++)
    {
        item_switch[0] = equipped[0];
    }

    size_t INVENTORY_SIZE = sizeof(inventory) / sizeof(inventory[0]);

    // List inventory
    printf("\nInventory: ");
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        printf("%s, ", inventory[i]);
    }

    // Get user input (id_001, id_002...)
    char equip[10];
    printf("\nEQUIPPING: ");
    scanf("%s", equip);

    // Unequip current item to insert into an empty slot
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
    bool empty_check = strcmp(inventory[i], "empty");
    if (empty_check == 0)
        {
            inventory[i] = equipped[0];
            break;
        }
    }

    // Find and remove duplicate
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        bool item_duplicate_check = strcmp(item_switch[0], inventory[i]);
        if (item_duplicate_check == 0)
        {
            inventory[i] = "empty";
            break;
        }
    }

    // Equip the user input and switch item
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        bool equip_check = strcmp(equip, inventory[i]);
        if (equip_check == 0)
        {
            equipped[0] = inventory[i];
            inventory[i] = item_switch[0];
            break;
        }
    }

    printf("Now equipped: %s\n", equipped[0]);
    printf("New inventory: ");
    
    // Show updated inventory
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        printf("%s, ", inventory[i]);
    }
}
