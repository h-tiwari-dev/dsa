def find_common_and_uncommon(list1, list2):
    common_elements = []
    uncommon_elements = []

    set1 = {tuple(sublist) for sublist in list1}
    set2 = {tuple(sublist) for sublist in list2}

    common = set1.intersection(set2)
    uncommon_in_list1 = set1 - common
    uncommon_in_list2 = set2 - common

    for sublist in uncommon_in_list1:
        uncommon_elements.append(list(sublist))

    for sublist in uncommon_in_list2:
        uncommon_elements.append(list(sublist))

    for sublist in common:
        common_elements.append(list(sublist))

    return common_elements, uncommon_elements

# Example lists
list1 = [["....Q","..Q..","Q....","...Q.",".Q..."],["....Q",".Q...","...Q.","Q....","..Q.."],["...Q.",".Q...","....Q","..Q..","Q...."],["...Q.",".Q...","....Q","Q....","..Q.."],["...Q.","Q....","..Q..","....Q",".Q..."],["..Q..","....Q",".Q...","...Q.","Q...."],["..Q..","....Q","Q....","...Q.",".Q..."],["..Q..","Q....","....Q",".Q...","...Q."],["..Q..","Q....","...Q.",".Q...","....Q"],[".Q...","....Q","..Q..","Q....","...Q."],[".Q...","...Q.","Q....","....Q","..Q.."],[".Q...","...Q.","Q....","..Q..","....Q"],["Q....","...Q.",".Q...","....Q","..Q.."],["Q....","..Q..","....Q",".Q...","...Q."]]

list2 = [["Q....","..Q..","....Q",".Q...","...Q."],["Q....","...Q.",".Q...","....Q","..Q.."],[".Q...","...Q.","Q....","..Q..","....Q"],[".Q...","....Q","..Q..","Q....","...Q."],["..Q..","Q....","...Q.",".Q...","....Q"],["..Q..","....Q",".Q...","...Q.","Q...."],["...Q.","Q....","..Q..","....Q",".Q..."],["...Q.",".Q...","....Q","..Q..","Q...."],["....Q",".Q...","...Q.","Q....","..Q.."],["....Q","..Q..","Q....","...Q.",".Q..."]]

common, uncommon = find_common_and_uncommon(list1, list2)

print("Common Elements:")
for sublist in common:
    print(sublist)

print("\nUncommon Elements:")
for sublist in uncommon:
    print(sublist)
