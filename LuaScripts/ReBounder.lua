print "Start of ReBounder"


ReBounder = class.new()

ReBounder.constructor = function ( self)

	self.xvel = 3
	self.yvel = 3
	setPosition(arg0, arg1)
end

ReBounder.update = function ( self )

	if getX() + 66 >= 600 or getX() <= 0 then
		self.xvel = -self.xvel
	end

	if getY() + 66 >= 600 or getY() <= 0 then
		self.yvel = -self.yvel
	end
	
	setPosition( getX() + self.xvel, getY() + self.yvel );
end

