/* Churkin Kirill st129364@student.spbu.ru
	Lab_work_2
*/

#include "Rarity.h"

Rarity upgradeRarity(Rarity r) {
    if (r == Rarity::U) return Rarity::R;
    if (r == Rarity::R) return Rarity::SR;
    return Rarity::SR;
}

Rarity downgradeRarity(Rarity r) {
    if (r == Rarity::SR) return Rarity::R;
    if (r == Rarity::R) return Rarity::U;
    return Rarity::U;
}
