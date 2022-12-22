/*
 * DIO.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Almodather
 */
#include "../STD_LIB/STD_Types.h"
#include "../STD_LIB/util.h"
#include "../MCAL/DIO/DIO_Private.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"



u8 DIO_u8set_pin_value(u8 Copy_u8_port_ID,u8 Copy_u8_pin_ID,u8 Copy_u8_pin_val)
{
	u8 Loc_u8Error_state=DIO_u8_ERROR_INIT_VAl;
	if ((Copy_u8_port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_port_ID<=MAX_u8_PORT_ID))
	{
		if((Copy_u8_pin_ID>=MIN_u8_PIN_ID)&&(Copy_u8_pin_ID<=MAX_u8_PIN_ID))
		{
			if((Copy_u8_pin_val==MIN_u8_PIN_VAL)||(Copy_u8_pin_val==MAX_u8_PIN_VAL))
					{
						switch(Copy_u8_port_ID)
							{
								case GROUP_A:
									Assign_Bit(DIO_U8_PORTA,Copy_u8_pin_ID,Copy_u8_pin_val);
									break;
								case GROUP_B:
									Assign_Bit(DIO_U8_PORTB,Copy_u8_pin_ID,Copy_u8_pin_val);
									break;
								case GROUP_C:
									Assign_Bit(DIO_U8_PORTC,Copy_u8_pin_ID,Copy_u8_pin_val);
									break;
								case GROUP_D:
									Assign_Bit(DIO_U8_PORTD,Copy_u8_pin_ID,Copy_u8_pin_val);
									break;

							}
					}
			else
				{
				Loc_u8Error_state=DIO_u8_PIN_VAL_ERROR;
				}

			}
		else
						{
			Loc_u8Error_state=DIO_u8_PIN_ID_ERROR;
						}



	}
	else
	{
			Loc_u8Error_state=DIO_u8_PORT_ID_ERROR;
	}

	return Loc_u8Error_state;
}

u8 DIO_u8set_pin_dir(u8 Copy_u8_port_ID,u8 Copy_u8_pin_ID,u8 Copy_u8_pin_dir)
{
	u8 Loc_u8Error_state=DIO_u8_ERROR_INIT_VAl;
		if ((Copy_u8_port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_port_ID<=MAX_u8_PORT_ID))
		{
			if((Copy_u8_pin_ID>=MIN_u8_PIN_ID)&&(Copy_u8_pin_ID<=MAX_u8_PIN_ID))
			{
				if((Copy_u8_pin_dir==MIN_u8_PIN_DIR)||(Copy_u8_pin_dir==MAX_u8_PIN_DIR))
						{
							switch(Copy_u8_port_ID)
								{
									case GROUP_A:
										Assign_Bit(DIO_U8_DDRA,Copy_u8_pin_ID,Copy_u8_pin_dir);
										break;
									case GROUP_B:
										Assign_Bit(DIO_U8_DDRB,Copy_u8_pin_ID,Copy_u8_pin_dir);
										break;
									case GROUP_C:
										Assign_Bit(DIO_U8_DDRC,Copy_u8_pin_ID,Copy_u8_pin_dir);
										break;
									case GROUP_D:
										Assign_Bit(DIO_U8_DDRD,Copy_u8_pin_ID,Copy_u8_pin_dir);
										break;

								}
						}
				else
					{
					Loc_u8Error_state=DIO_u8_PIN_DIR_ERROR;
					}

				}
			else
							{
				Loc_u8Error_state=DIO_u8_PIN_ID_ERROR;
							}



		}
		else
		{
				Loc_u8Error_state=DIO_u8_PORT_ID_ERROR;
		}

		return Loc_u8Error_state;

}

u8 DIO_u8set_port_value(u8 Copy_u8_port_ID,u8 Copy_u8_port_val)
{
	u8 Loc_u8Error_state=DIO_u8_ERROR_INIT_VAl;
			if ((Copy_u8_port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_port_ID<=MAX_u8_PORT_ID))
			{
				//solution  for this problem
					if((Copy_u8_port_val>=MIN_u8_PORT_VAL)||(Copy_u8_port_val<=MAX_u8_PORT_VAL))
							{
								switch(Copy_u8_port_ID)
									{
										case GROUP_A:
											DIO_U8_PORTA=Copy_u8_port_val;
											//Assign_Bit(DIO_U8_PORTA,Copy_u8_pin_ID,Copy_u8_port_val);
											break;
										case GROUP_B:
											DIO_U8_PORTB=Copy_u8_port_val;
											//Assign_Bit(DIO_U8_PORTB,Copy_u8_pin_ID,Copy_u8_port_val);
											break;
										case GROUP_C:
											DIO_U8_PORTC=Copy_u8_port_val;
											//Assign_Bit(DIO_U8_PORTC,Copy_u8_pin_ID,Copy_u8_port_val);
											break;
										case GROUP_D:
											DIO_U8_PORTD=Copy_u8_port_val;
											//Assign_Bit(DIO_U8_PORTD,Copy_u8_pin_ID,Copy_u8_port_val);
											break;

									}
							}
					else
						{
						Loc_u8Error_state=DIO_u8_PORT_VAL_ERROR;
						}

			}

			else
			{
					Loc_u8Error_state=DIO_u8_PORT_ID_ERROR;
			}

			return Loc_u8Error_state;
}

u8 DIO_u8set_port_dir(u8 Copy_u8_port_ID,u8 Copy_u8_port_dir)
{
	u8 Loc_u8Error_state=DIO_u8_ERROR_INIT_VAl;
			if ((Copy_u8_port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_port_ID<=MAX_u8_PORT_ID))
			{
				//solution  for this problem
					if((Copy_u8_port_dir==MIN_u8_PORT_DIR)||(Copy_u8_port_dir==MAX_u8_PORT_DIR))
							{
								switch(Copy_u8_port_ID)
									{
										case GROUP_A:
											DIO_U8_DDRA=Copy_u8_port_dir;
											//Assign_Bit(DIO_U8_PORTA,Copy_u8_pin_ID,Copy_u8_port_val);
											break;
										case GROUP_B:
											DIO_U8_DDRB=Copy_u8_port_dir;
											//Assign_Bit(DIO_U8_PORTB,Copy_u8_pin_ID,Copy_u8_port_val);
											break;
										case GROUP_C:
											DIO_U8_DDRC=Copy_u8_port_dir;
											//Assign_Bit(DIO_U8_PORTC,Copy_u8_pin_ID,Copy_u8_port_val);
											break;
										case GROUP_D:
											DIO_U8_DDRD=Copy_u8_port_dir;
											//Assign_Bit(DIO_U8_PORTD,Copy_u8_pin_ID,Copy_u8_port_val);
											break;

									}
							}
					else
						{
						Loc_u8Error_state=DIO_u8_PORT_DIR_ERROR;
						}

			}

			else
			{
					Loc_u8Error_state=DIO_u8_PORT_ID_ERROR;
			}

			return Loc_u8Error_state;
}

u8 DIO_u8get_pin_value(u8 Copy_u8_port_ID,u8 Copy_u8_pin_ID,u8 *Copy_u8_pin_val)
{
	u8 Loc_u8Error_state=DIO_u8_ERROR_INIT_VAl;
		if ((Copy_u8_port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_port_ID<=MAX_u8_PORT_ID))
		{
			if((Copy_u8_pin_ID>=MIN_u8_PIN_ID)&&(Copy_u8_pin_ID<=MAX_u8_PIN_ID))
			{

							switch(Copy_u8_port_ID)
								{
									case GROUP_A:
										*Copy_u8_pin_val = get_bit(DIO_U8_PINA,Copy_u8_pin_ID);
										break;
									case GROUP_B:
										*Copy_u8_pin_val = get_bit(DIO_U8_PINB,Copy_u8_pin_ID);
										break;
									case GROUP_C:
										*Copy_u8_pin_val = get_bit(DIO_U8_PINC,Copy_u8_pin_ID);
										break;
									case GROUP_D:
										*Copy_u8_pin_val = get_bit(DIO_U8_PIND,Copy_u8_pin_ID);
										break;

								}



				}
			else
							{
				Loc_u8Error_state=DIO_u8_PIN_ID_ERROR;
							}



		}
		else
		{
				Loc_u8Error_state=DIO_u8_PORT_ID_ERROR;
		}

		return Loc_u8Error_state;
}

u8 DIO_u8Get_port_value(u8 Copy_u8_port_ID,u8 *Copy_u8_port_val)
{
	u8 Loc_u8Error_state=DIO_u8_ERROR_INIT_VAl;
			if ((Copy_u8_port_ID>=MIN_u8_PORT_ID)&&(Copy_u8_port_ID<=MAX_u8_PORT_ID))
			{

								switch(Copy_u8_port_ID)
									{
										case GROUP_A:
											*Copy_u8_port_val = DIO_U8_PINA;
											break;
										case GROUP_B:
											*Copy_u8_port_val = DIO_U8_PINB;
											break;
										case GROUP_C:
											*Copy_u8_port_val = DIO_U8_PINC;
											break;
										case GROUP_D:
											*Copy_u8_port_val =DIO_U8_PIND;
											break;

									}



			}

			else
			{
					Loc_u8Error_state=DIO_u8_PORT_ID_ERROR;
			}

			return Loc_u8Error_state;

}
