function sort(list)
    list:setSwapTimeout(5)

    n = list:getRectCount()
    while n > 1 and getRunning() do
        for i = 0, n - 2, 1 do
            if list:getValue(i) > list:getValue(i + 1) then
                list:swap(i, i + 1)
            end
        end
        n = n - 1
    end
end