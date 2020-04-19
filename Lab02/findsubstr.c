int find_sub_str(const char* str, const char* sub) {
    int pos_in_str = 0;
    int pos_in_sub = 0;
    int temp_pos = 0;

    while (*(str + pos_in_str)) {
        pos_in_sub = 0;
        temp_pos = pos_in_str;
        if (*(str + pos_in_str) == *(sub + pos_in_sub)) {
            while (*(sub + pos_in_sub) == *(str + pos_in_str) && *(sub + pos_in_sub) && *(str + pos_in_str)) {
                pos_in_sub++;
                pos_in_str++;
            }
            if (*(sub + pos_in_sub)) return 1;
        }
        pos_in_str = temp_pos + 1;
    }
    return -1;
}