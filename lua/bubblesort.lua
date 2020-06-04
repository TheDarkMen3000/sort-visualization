function sort(list)
    n = list:getRectCount()
    while n > 1 and getRunning() do
        for i = 0, n - 2, 1 do
            if list:getRect(i):getValue() > list:getRect(i + 1):getValue() then
                list:swap(i, i + 1)
            end
        end
        n = n - 1
    end
end