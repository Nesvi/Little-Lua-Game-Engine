print( "Start of Example entity");

ExampleEntity = class.new();

ExampleEntity.constructor = function (self)
	
	print("Im being build");
	setPosition( 300, 300)
end

ExampleEntity.update = function (self)
	--Random movement
	setPosition(getX() + math.random(5) -3, getY() + math.random(5) -3 )
end
