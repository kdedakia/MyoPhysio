#ifndef VIEW_H_
#define VIEW_H_

#include "model.h"

class View {

public:
	virtual void update(Model *model) = 0;

};

#endif	// VIEW_H_