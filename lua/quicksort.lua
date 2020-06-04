function partition(list, left, right)
    if getRunning() then
        local x = list:getValue(right)
        local i = left - 1
        
        for j = left, right - 1 do
            if list:getValue(j) <= x then
                i = i + 1
                list:swap(i, j)
            end
        end
        list:swap(i + 1, right)

        return i + 1
    else
        return 0
    end
end

function quicksort(list, left, right)
    if right > left and getRunning() then
        local pivotNewIndex = partition(list, left, right, left)
        quicksort(list, left, pivotNewIndex - 1)
        quicksort(list, pivotNewIndex + 1, right)
    end
end

function sort(list)
    list:setSwapTimeout(50)

    quicksort(list, 0, list:getRectCount() - 1)
end