#ifndef MCAL_MFMI_MFMI_INTERFACE_H_
#define MCAL_MFMI_MFMI_INTERFACE_H_


void MFMI_vEraseAppArea(void);
void MFMI_vSectorErase(u8 A_u8SectorNo);
void MFMI_vFlashWrite(u32 A_u32Address,u16* A_pu16Data,u16  A_u16Length);


#endif /* MCAL_MFMI_MFMI_INTERFACE_H_ */
