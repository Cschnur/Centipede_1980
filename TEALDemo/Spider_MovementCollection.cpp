#include "Spider_MovementCollection.h"
#include "Spider_OffsetArray.h"

const Spider_OffsetArray Spider_MovementCollection::LeftAndDown = Spider_OffsetArray(-1, 1);
const Spider_OffsetArray Spider_MovementCollection::LeftAndUp = Spider_OffsetArray(-1, -1);
const Spider_OffsetArray Spider_MovementCollection::RightAndDown = Spider_OffsetArray(1, 1);
const Spider_OffsetArray Spider_MovementCollection::RightAndUp = Spider_OffsetArray(1, -1);
const Spider_OffsetArray Spider_MovementCollection::Down = Spider_OffsetArray(0, 1);
const Spider_OffsetArray Spider_MovementCollection::Up = Spider_OffsetArray(0, -1);
