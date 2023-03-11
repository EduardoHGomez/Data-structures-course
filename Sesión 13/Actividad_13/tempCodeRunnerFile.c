        for (int j = 0; j < size; j++)
        {
            if (j % lista[i] == 0)
            {
                lista[size] = i;
                size++;
            }
        }
        
    }