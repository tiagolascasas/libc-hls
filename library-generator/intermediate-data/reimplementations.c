double atof(char const* string)
{
    if (string == (char const*)0)
    {
        return 0.0;
    }

    double result        = 0.0;
    double fraction      = 0.0;
    double divisor       = 10.0;
    int    sign          = 1;
    int    exponent_sign = 1;
    int    exponent      = 0;
    int    has_fraction  = 0;

    while (*string == ' ' || *string == '\t' || *string == '\n' || *string == '\r')
    {
        string++;
    }

    if (*string == '-')
    {
        sign = -1;
        string++;
    }
    else if (*string == '+')
    {
        string++;
    }

    while (*string >= '0' && *string <= '9')
    {
        result = result * 10.0 + (*string - '0');
        string++;
    }

    if (*string == '.')
    {
        has_fraction = 1;
        string++;
        while (*string >= '0' && *string <= '9')
        {
            fraction += (*string - '0') / divisor;
            divisor *= 10.0;
            string++;
        }
    }
    result += fraction;

    if (*string == 'e' || *string == 'E')
    {
        string++;
        if (*string == '-')
        {
            exponent_sign = -1;
            string++;
        }
        else if (*string == '+')
        {
            string++;
        }

        while (*string >= '0' && *string <= '9')
        {
            exponent = exponent * 10 + (*string - '0');
            string++;
        }

        if (exponent != 0)
        {
            double power = 1.0;
            for (int i = 0; i < exponent; i++)
            {
                power *= 10.0;
            }
            if (exponent_sign == -1)
            {
                result /= power;
            }
            else
            {
                result *= power;
            }
        }
    }

    return sign * result;
}