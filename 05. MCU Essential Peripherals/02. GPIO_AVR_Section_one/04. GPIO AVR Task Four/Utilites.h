
/* File Guards to protect from recursive inclusion.*/
#ifndef UTILITES_H_
#define UTILITES_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BITNUMBER)          (REG|=(1<<BITNUMBER))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BITNUMBER)         (REG&=(~(1<<BITNUMBER)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BITNUMBER)       (REG^=(1<<BITNUMBER))

/* Get a certain bit in any register */
#define GET_BIT(REG,BITNUMBER)          ((REG&(1<<BITNUMBER))>>BITNUMBER)

/* Assign a certain value to a certain bit in any register */
#define ASSIGNBITINREG(REG,BITNUMBER,VALUE)   (REG=(REG&(~(1<<BITNUMBER)))|(VALUE<<BITNUMBER))

/* Set a certain bits Seq. in any register */
#define SET_BITS_BY_Value(REG,Value,BITNUMBER)          (REG|=(Value<<BITNUMBER))

/* Clear a certain bits Seq. in any register */
#define CLEAR_BITS_BY_Value(REG,Value,BITNUMBER)         (REG&=(~(Value<<BITNUMBER)))

/* Toggle a certain bits Seq. in any register */
#define TOGGLE_BITS_BY_Value(REG,Value,BITNUMBER)       (REG^=(Value<<BITNUMBER))

#endif /* UTILITES_H_ */
