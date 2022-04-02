#include "Ui.h"

UI  create_UI(EstateService* serv)
{
    UI ui ;
    ui.serv = serv;
    //input_estates(serv);
    return ui;
}
/*
void destroy(UI * ui)
{
    destroy_service(ui -> serv);
    free(ui);
}
*/
int get_integer(const char* msg)
{
    int nr = 0;
    char s[10];
    int ok = 0;
    int check = 0;
    while (ok == 0) {
        printf("%s", msg);
        scanf("%s", s);
        check = sscanf(s, "%d", &nr);
        if (check == 1)
            ok = 1;
        else
            printf("> Please give an integer! \n ");
    }
    return nr;
}

void input_estates(UI* ui)
{
    add_service(ui->serv, "apartment", "Garii", 104, 60000);
    add_service(ui->serv, "house", "Intre Lacuri", 240, 453400);
    add_service(ui->serv, "penthouse", "Vlad Tepes", 700, 34245);
    add_service(ui->serv, "apartment", "Marasti", 3663, 4000);
    add_service(ui->serv, "penthouse", "Traian", 312, 56440);
    add_service(ui->serv, "house", "Centru Vehi", 675, 7688);
    add_service(ui->serv, "penthouse", "Unirii", 240, 5323);
    add_service(ui->serv, "apartment", "Zorilor", 566, 6000);
    add_service(ui->serv, "penthouse", "Bucuresti", 240, 45350);
    add_service(ui->serv, "house", "Mihai Eminescu", 888, 80000);
}

void print_estates(UI* ui)
{
    DynamicArray* array = get_array(ui->serv);
    for(int i=0; i < len(array); i++)
    {
        char str[50];
        to_string(find_elem_on_pos(array, i), str);
        printf("%s\n", str);
    }


}

void add_ui(UI* ui)
{
    char type[20], address[100];
    double price, surface;
    printf("> Add the type: ");
    scanf("%s", type);
    printf("> Add the address: ");
    scanf("%s", address);
    surface = get_integer("> Add the surface: ");
    price = get_integer("> Add the price: ");
    int result = add_service(ui->serv, type, address, surface, price);
    if (result == 0)
        printf("> Invalid input! The estate was not added\n");
}

void delete_ui(UI* ui)
{
    char address[100];
    printf("> Give the address: ");
    scanf("%s", address);
    int result = delete_service(ui->serv, address);
    if (result == 0)
        printf("> Invalid input! The estate was not deleted.\n");
}

void update_ui(UI* ui)
{
    char address[100], new_type[20];
    double new_price, new_surface;
    printf("> Insert an address in order to update the estate: ");
    scanf("%s", address);
    printf("> new type: ");
    scanf("%s", new_type);
    new_surface = get_integer("> new surface :");
    new_price = get_integer("> new price :");
    int position = search_by_attributes(ui->serv , address);
    int result = update_service(ui->serv,position , address, new_type, new_surface, new_price);
    if (result == 0)
    {
        printf("> The address is invalid or it does not exist. Please try again.\n");

    }

}
/*
void filter_ui(UI* ui)
{
    char str[30], s[170];
    printf("> Search for: ");
    scanf("%s", str);
    if (strcmp(str, "null") == 0)
        print_estates(ui);
    else
    {
        int i;
        EstateRepository* repo = filter_address(ui->serv, str);
        if (get_repo_length(repo) == 0)
            printf("> No items matching te requested address.\n");
        else
        {
            repo = sort_repository(ui->serv, repo);
            for (i = 0; i < repo->estates->length; i++)
            {
                to_string(repo->estates->elems[i], s);
                printf("%s\n", s);
            }
        }
    destroy_repository(repo);
    }
}

void filter2_ui(UI* ui) {
    char type[40], s[100];
    double sr;
    sr = get_integer("> surface: ");
    EstateRepository *new_repo = filter_surface(ui->serv, sr, ui->serv->repo);
    new_repo = filter_surface(ui->serv, sr, new_repo);
    if (get_repo_length(new_repo) == 0)
        printf("> NO ITEMS MATCHING\n");
    else {
        new_repo = sort_repository(ui->serv, new_repo);
        for (int i = 0; i < new_repo->estates->length; i++) {
            to_string(new_repo->estates->elems[i], s);
            printf("%s\n", s);
        }
    destroy_repository(new_repo);
    }
}
 */
    void print_menu() {

        printf("1.List all estates\n");
        printf("2.Add an estate\n");
        printf("3.Delete an estate\n");
        printf("4.Update an estate\n");
        printf("5.Display all estates whose address contains a given string sorted ascending by their price\n");
        printf("6.Display all estates with a given surface, sorted ascending by their price\n");
        printf("0.Exit\n");
    }

    void run(UI *ui) {
        input_estates(ui);

        while (1) {
            print_menu();
            int cmd = get_integer("> Please give a command: ");
            if (cmd < 0 || cmd > 4) {
                printf("> Invalid command! Try again using an integer\n");
                continue;
            } else {
                if (cmd == 0)
                    break;
                else if (cmd == 1)
                    print_estates(ui);
                else if (cmd == 2)
                    add_ui(ui);
                else if (cmd == 3)
                    delete_ui(ui);
                else if (cmd == 4)
                    update_ui(ui);
                //else if (cmd == 5)
                    //filter_ui(ui);
                //else if (cmd == 6)
                    //filter2_ui(ui);
            }
        }
    }
