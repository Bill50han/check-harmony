#include <iostream>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <algorithm>

int main()
{
    std::cout << "请输入和弦组成音的数量：\n";
    size_t len;
    std::cin >> len;
    char cnote[3] = { 0 };
    uint16_t unote = 0;
    std::vector<uint16_t> notes(0);

    std::cout << "请输入所有的和弦组成音，一行一个，半音只支持bX的形式：\n";
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> cnote;
        switch ((*(uint16_t*)cnote))
        {
        case 'C':
            unote = 1;
            notes.push_back(unote);
            break;
        case 'G':
            unote = 2;
            notes.push_back(unote);
            break;
        case 'D':
            unote = 3;
            notes.push_back(unote);
            break;
        case 'A':
            unote = 4;
            notes.push_back(unote);
            break;
        case 'E':
            unote = 5;
            notes.push_back(unote);
            break;
        case 'B':
            unote = 6;
            notes.push_back(unote);
            break;
        case 'Gb':
            unote = 7;
            notes.push_back(unote);
            break;
        case 'Db':
            unote = 8;
            notes.push_back(unote);
            break;
        case 'Ab':
            unote = 9;
            notes.push_back(unote);
            break;
        case 'Eb':
            unote = 10;
            notes.push_back(unote);
            break;
        case 'Bb':
            unote = 11;
            notes.push_back(unote);
            break;
        case 'F':
            unote = 12;
            notes.push_back(unote);
            break;
            //std::cout << cnote;
        default:
            std::cout << "不是音符！\n";
            i--;
            break;
        }
    }

    std::sort(notes.begin(), notes.end());
    notes.push_back(notes[0] + 12);

    for (auto it = notes.begin() + 1; it != notes.end(); it++)
    {
        //std::cout << *(it - 1) << "," << *it << "\n";
        if ((*it - *(it - 1)) > 6)
        {
            goto low;
        }
        else if ((*it - *(it - 1)) == 6)
        {
            goto mid;
        }
    }
high:
    std::cout << "这个和弦的张力非常大。" << std::endl;
    goto end;

low:
    std::cout << "这个和弦的张力不太大。" << std::endl;
    goto end;
mid:
    std::cout << "这个和弦的张力较大。" << std::endl;
    goto end;


end:
    return 0;
}
