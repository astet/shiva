--
-- Created by IntelliJ IDEA.
-- User: romansztergbaum
-- Date: 23/06/2018
-- Time: 08:20
-- To change this template use File | Settings | File Templates.
--

function internal_update()
    print("delta: " .. shiva.fixed_delta_time)
end

example_system_table = {
    update = internal_update,
    current_system_type = system_type.pre_update
}

