#include "KeyPad_Interface.h"

void KPD_Init()
{
    /* Rows Input With Internal Pull Up */

    DIO_DirectionSelectforPin(KPD_R0Group,KPD_R0Pin,DIO_Inputfor1Pin);
    DIO_DirectionSelectforPin(KPD_R1Group,KPD_R1Pin,DIO_Inputfor1Pin);
    DIO_DirectionSelectforPin(KPD_R2Group,KPD_R2Pin,DIO_Inputfor1Pin);
    DIO_DirectionSelectforPin(KPD_R3Group,KPD_R3Pin,DIO_Inputfor1Pin);

    DIO_WritePin(KPD_R0Group,KPD_R0Pin,DIO_Highfor1Pin);
    DIO_WritePin(KPD_R1Group,KPD_R1Pin,DIO_Highfor1Pin);
    DIO_WritePin(KPD_R2Group,KPD_R2Pin,DIO_Highfor1Pin);
    DIO_WritePin(KPD_R3Group,KPD_R3Pin,DIO_Highfor1Pin);

    /* Columns Output High */

    DIO_DirectionSelectforPin(KPD_C0Group,KPD_C0Pin,DIO_Outputfor1Pin);
    DIO_DirectionSelectforPin(KPD_C1Group,KPD_C1Pin,DIO_Outputfor1Pin);
    DIO_DirectionSelectforPin(KPD_C2Group,KPD_C2Pin,DIO_Outputfor1Pin);
    DIO_DirectionSelectforPin(KPD_C3Group,KPD_C3Pin,DIO_Outputfor1Pin);

    DIO_WritePin(KPD_C0Group,KPD_C0Pin,DIO_Highfor1Pin);
    DIO_WritePin(KPD_C1Group,KPD_C1Pin,DIO_Highfor1Pin);
    DIO_WritePin(KPD_C2Group,KPD_C2Pin,DIO_Highfor1Pin);
    DIO_WritePin(KPD_C3Group,KPD_C3Pin,DIO_Highfor1Pin);
}

uint8_t KPD_GetPressedKey(void)
{
    uint8_t RowsPins[KPD_ROWS_NUM] =
    {
        KPD_R0Pin,
        KPD_R1Pin,
        KPD_R2Pin,
        KPD_R3Pin
    };

    uint8_t RowsGroups[KPD_ROWS_NUM] =
    {
        KPD_R0Group,
        KPD_R1Group,
        KPD_R2Group,
        KPD_R3Group
    };

    uint8_t ColumnsPins[KPD_COLS_NUM] =
    {
        KPD_C0Pin,
        KPD_C1Pin,
        KPD_C2Pin,
        KPD_C3Pin
    };

    uint8_t ColumnsGroups[KPD_COLS_NUM] =
    {
        KPD_C0Group,
        KPD_C1Group,
        KPD_C2Group,
        KPD_C3Group
    };

    uint8_t ButtonValues[KPD_ROWS_NUM][KPD_COLS_NUM] = KPD_ButtonValue;

    uint8_t RowIndex = 0;
    uint8_t ColumnIndex = 0;
    uint8_t ButtonState = DIO_Highfor1Pin;

    for(ColumnIndex=0;ColumnIndex<KPD_COLS_NUM;ColumnIndex++)
    {
        DIO_WritePin(ColumnsGroups[ColumnIndex],
                     ColumnsPins[ColumnIndex],
                     DIO_Lowfor1Pin);

        for(RowIndex=0;RowIndex<KPD_ROWS_NUM;RowIndex++)
        {
            DIO_ReadPin(RowsGroups[RowIndex],
                        RowsPins[RowIndex],
                        &ButtonState);

            if(ButtonState==DIO_Lowfor1Pin)
            {
                DIO_WritePin(ColumnsGroups[ColumnIndex],
                             ColumnsPins[ColumnIndex],
                             DIO_Highfor1Pin);

                return ButtonValues[RowIndex][ColumnIndex];
            }
        }

        DIO_WritePin(ColumnsGroups[ColumnIndex],
                     ColumnsPins[ColumnIndex],
                     DIO_Highfor1Pin);
    }

    return KPD_NotPressed;
}