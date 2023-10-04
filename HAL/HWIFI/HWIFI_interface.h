#ifndef HAL_HWIFI_HWIFI_INTERFACE_H
#define HAL_HWIFI_HWIFI_INTERFACE_H

void HWIFI_voidInit(void);
void HWIFI_voidConnectToNetwork (void);
void HWIFI_voidConnectToServer (void);
u8 HWIFI_u8GetData (u8 *data_array);

#endif /* HAL_HWIFI_HWIFI_INTERFACE_H */
