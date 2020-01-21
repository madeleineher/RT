function check_val(val)
{
    return ((val == '') ? "0" : val);
}

function check_multi_val(vals)
{
    var final = [3];

    final[0] = (vals[0].value == '') ? "0" : vals[0].value;
    final[1] = (vals[1].value == '') ? "0" : vals[1].value;
    final[2] = (vals[2].value == '') ? "0" : vals[2].value;
    return (final);
}

function get_sph_att(tmp)
{
    var sph_cen = check_multi_val(document.getElementsByName('center_s')); 
    var sph_rad = check_val(document.getElementById('sph_rad').value);

    tmp = "\t\t\t<center> " + sph_cen[2] + ", " + sph_cen[1] + ", " + sph_cen[0] + " </center>\n";
    tmp += "\t\t\t<radius> " + sph_rad + " </radius>\n";
    return (tmp);
}

function get_con_att(tmp)
{
    var con_cen = check_multi_val(document.getElementsByName('center_c'));
    var con_axis = check_multi_val(document.getElementsByName('axis_c'));
    var con_ang = check_val(document.getElementById('con_ang').value);
    var con_uheight = check_val(document.getElementById('con_uheight').value);
    var con_lheight = check_val(document.getElementById('con_lheight').value);

    tmp = "\t\t\t<center> " + con_cen[2] + ", " + con_cen[1] + ", " + con_cen[0] + " </center>\n";
    tmp += "\t\t\t<axis> " + con_axis[2] + ", " + con_axis[1] + ", " + con_axis[0] + " </axis>\n";
    tmp += "\t\t\t<angle> " + con_ang + " </angle>\n";
    tmp += "\t\t\t<lower_height> " + con_lheight + " </lower_height>\n";
    tmp += "\t\t\t<upper_height> " + con_uheight + " </upper_height>\n";
    return (tmp);
}

function get_cyn_att(tmp)
{
    var cyn_cen = check_multi_val(document.getElementsByName('center_y'));
    var cyn_axis = check_multi_val(document.getElementsByName('axis_y'));
    var cyn_rad = check_val(document.getElementById('cyn_rad').value);
    var cyn_height = check_val(document.getElementById('cyn_height').value);

    tmp = "\t\t\t<center> " + cyn_cen[2] + ", " + cyn_cen[1] + ", " + cyn_cen[0] + " </center>\n";
    tmp += "\t\t\t<axis> " + cyn_axis[2] + ", " + cyn_axis[1] + ", " + cyn_axis[0] + " </axis>\n";
    tmp += "\t\t\t<radius> " + cyn_rad + " </radius>\n";
    tmp += "\t\t\t<height> " + cyn_height + " </height>\n";
    return (tmp);
}

function get_rec_att(tmp)
{
    var point = check_multi_val(document.getElementsByName('rec_point'));
    var vecA = check_multi_val(document.getElementsByName('rec_vector_a'));
    var vecB = check_multi_val(document.getElementsByName('rec_vector_b'));
    
    tmp = "\t\t\t<p> " + point[2] + ", " + point[1] + ", " + point[0] + " </p>\n";
    tmp += "\t\t\t<a> " + vecA[2] + ", " + vecA[1] + ", " + vecA[0] + " </a>\n";
    tmp += "\t\t\t<b> " + vecB[2] + ", " + vecB[1] + ", " + vecB[0] + " </b>\n";
    return(tmp);
}

function get_rin_att(tmp)
{
    var ring_cen = check_multi_val(document.getElementsByName('center_r'));
    var ring_nor = check_multi_val(document.getElementsByName('ri_normal'));
    var ring_inn_rad = check_val(document.getElementById('ring_inn_rad').value);
    var ring_out_rad = check_val(document.getElementById('ring_out_rad').value);

    tmp = "\t\t\t<center> " + ring_cen[2] + ", " + ring_cen[1] + ", " + ring_cen[0] + " </center>\n";
    tmp += "\t\t\t<normal> " + ring_nor[2] + ", " + ring_nor[1] + ", " + ring_nor[0] + " </normal>\n";
    tmp += "\t\t\t<r_one> " + ring_inn_rad + " </r_one>\n";
    tmp += "\t\t\t<r_two> " + ring_out_rad + " </r_two>\n";
    return(tmp);
}

function get_box_att(tmp)
{
    var box_point = check_multi_val(document.getElementsByName('box_point'));
    var box_vec_a = check_multi_val(document.getElementsByName('box_vector_a'));
    var box_vec_b = check_multi_val(document.getElementsByName('box_vector_b'));
    var box_lenC = check_val(document.getElementById('box_lenC').value);

    tmp = "\t\t\t<vmin> " + box_point[2] + ", " + box_point[1] + ", " + box_point[0] + " </vmin>\n";
    tmp += "\t\t\t<a> " + box_vec_a[2] + ", " + box_vec_a[1] + ", " + box_vec_a[0] + " </a>\n";
    tmp += "\t\t\t<b> " + box_vec_b[2] + ", " + box_vec_b[1] + ", " + box_vec_b[0] + " </b>\n";
    tmp += "\t\t\t<norm_c> " + box_lenC + " </norm_c>\n";
    return(tmp);
}

function get_pyr_att(tmp)
{
    var pyr_point = check_multi_val(document.getElementsByName('py_point'));
    var pyr_vecV = check_multi_val(document.getElementsByName('vector_u'));
    var pyr_vecU = check_multi_val(document.getElementsByName('vector_v'));
    var pyr_height = check_val(document.getElementById('pyr_height').value);

    tmp = "\t\t\t<a> " + pyr_point[2] + ", " + pyr_point[1] + ", " + pyr_point[0] + " </a>\n";
    tmp += "\t\t\t<u> " + pyr_vecV[2] + ", " + pyr_vecV[1]  + ", " + pyr_vecV[0]  + " </u>\n";
    tmp += "\t\t\t<v> " + pyr_vecU[2] + ", " + pyr_vecU[1] + ", " + pyr_vecU[0] + " </v>\n";
    tmp += "\t\t\t<height> " + pyr_height + " </height>\n";
    return(tmp);
}

function get_tri_att(tmp)
{
    var tri_point = check_multi_val(document.getElementsByName('tr_point'));
    var tri_vecAB = check_multi_val(document.getElementsByName('vector_ab'));
    var tri_vecAC = check_multi_val(document.getElementsByName('vector_ac'));

    tmp = "\t\t\t<a> " + tri_point[2] + ", " + tri_point[1] + ", " + tri_point[0] + " </a>\n";
    tmp += "\t\t\t<ab> " + tri_vecAB[2] + ", " + tri_vecAB[1] + ", " + tri_vecAB[0] + " </ab>\n";
    tmp += "\t\t\t<ac> " + tri_vecAC[2] + ", " + tri_vecAC[1] + ", " + tri_vecAC[0] + " </ac>\n";
    return(tmp);
}

function get_pla_att(tmp)
{
    var pla_normal = check_multi_val(document.getElementsByName('pla_normal'));
    var pla_lenC = check_val(document.getElementById('pla_len_c'));

    tmp = "\t\t\t<normal> " + pla_normal[2] + ", " + pla_normal[1] + ", " + pla_normal[0] + " </normal>\n";
    tmp += "\t\t\t<d> " + pla_lenC.value + " </d>\n";
    return (tmp);
}

function get_par_att(tmp)
{
    var par_cen = check_multi_val(document.getElementsByName('center_pa'));
    var par_axis = check_multi_val(document.getElementsByName('axis_pa'));
    var par_uheight = check_val(document.getElementById('pa_uheight').value);
    var par_lheight = check_val(document.getElementById('pa_lheight').value);
    var par_narrow = check_val(document.getElementById('narrow').value);

    tmp = "\t\t\t<center> " + par_cen[2] + ", " + par_cen[1] + ", " + par_cen[0] + " </center>\n";
    tmp += "\t\t\t<axis> " + par_axis[2] + ", " + par_axis[1] + ", " + par_axis[0] + " </axis>\n";
    tmp += "\t\t\t<min> " + par_lheight + " </min>\n";
    tmp += "\t\t\t<max> " + par_uheight + " </max>\n";
    tmp += "\t\t\t<k> " + par_uheight + " </k>\n";
    return (tmp);
}

function get_ell_att(tmp)
{
    var ell_cen = check_multi_val(document.getElementsByName('center_ep'));
    var ell_axis = check_multi_val(document.getElementsByName('axis_ep'));
    var ell_lenc = check_val(document.getElementById('ep_len_c').value);
    var ell_sum = check_val(document.getElementById('sum').value);

    tmp = "\t\t\t<center> " + ell_cen[2] + ", " + ell_cen[1] + ", " + ell_cen[0] + " </center>\n";
    tmp += "\t\t\t<axis> " + ell_axis[2] + ", " + ell_axis[1] + ", " + ell_axis[0] + " </axis>\n";
    tmp += "\t\t\t<d> " + ell_lenc + " </d>\n";
    tmp += "\t\t\t<sum> " + ell_sum + " </sum>\n";
    return (tmp);
}

function get_parallel_attributes(shape_num)
{
    var tmp;
    var ior = document.getElementsByName('ior');
    var color_r = document.getElementsByName('color_r');
    var color_g = document.getElementsByName('color_g');
    var color_b = document.getElementsByName('color_b');
    var transparency = document.getElementsByName('transparency');
    var specpower = document.getElementsByName('specpower');
    var specvalue = document.getElementsByName('specvalue');
    var reflectivity = document.getElementsByName('reflectivity');

    tmp = "\t\t\t<optional>\n";
    tmp += "\t\t\t\t<ior> " + check_val(ior[shape_num].value) + " </ior>\n";
    tmp += "\t\t\t\t<color> " + check_val(color_r[shape_num].value) + ", " + check_val(color_g[shape_num].value) + ", " + check_val(color_b[shape_num].value) + " </color>\n";
    tmp += "\t\t\t\t<transparency> " + check_val(transparency[shape_num].value) + " </transparency>\n";
    tmp += "\t\t\t\t<specvalue> " + check_val(specvalue[shape_num].value) + " </specvalue>\n";
    tmp += "\t\t\t\t<specpower> " + check_val(specpower[shape_num].value) + " </specpower>\n";
    tmp += "\t\t\t\t<reflectivity> " + check_val(reflectivity[shape_num].value) + " </reflectivity>\n";
    tmp += "\t\t\t</optional>\n";
    return (tmp);
}

function get_mapping()
{
    var mapped = $('input[name=radio-207]:checked', '#mapping').val();
    if (mapped != null)
        return ("\t\t\t\t<file>" + mapped + ".jpg</file>\n");
    else
        return (0);
}

function get_bumping()
{
    var bumped = $('input[name=radio-208]:checked', '#bumping').val();
    if (bumped != null)
        return ("\t\t\t\t<file>" + bumped + ".jpg</file>\n");
    else
        return (0);
}

function close_shape(shape)
{
    return ("\t\t</" + shape + ">\n");
}

function create_xml(shape)
{
    var xml_shape = "\t\t<" + shape + ">\n";
    var shape_num = 0;
    var tmp;

    if (shape.localeCompare("sphere") == 0)
        xml_shape += get_sph_att(tmp);
    if (shape.localeCompare("cone") == 0)
    {
        shape_num = 1;
        xml_shape += get_con_att(tmp);
    }
    if (shape.localeCompare("cylinder") == 0)
    {
        shape_num = 2;
        xml_shape += get_cyn_att(tmp);
    }
    if (shape.localeCompare("rectangle") == 0)
    {
        shape_num = 3;
        xml_shape += get_rec_att(tmp);
    }
    if (shape.localeCompare("ring") == 0)
    {
        shape_num = 4;
        xml_shape += get_rin_att(tmp);
    }
    if (shape.localeCompare("box") == 0)
    {
        shape_num = 5;
        xml_shape += get_box_att(tmp);
    }
    if (shape.localeCompare("pyramid") == 0)
    {
        shape_num = 6;
        xml_shape += get_pyr_att(tmp);
    }
    if (shape.localeCompare("triangle") == 0)
    {
        shape_num = 7;
        xml_shape += get_tri_att(tmp);
    }
    if (shape.localeCompare("plane") == 0)
    {
        shape_num = 8;
        xml_shape += get_pla_att(tmp);
    }   
    if (shape.localeCompare("paraboloid") == 0)
    {
        shape_num = 9;
        xml_shape += get_par_att(tmp);
    }
    if (shape.localeCompare("ellipsoid") == 0)
    {
        shape_num = 10;
        xml_shape += get_ell_att(tmp);
    }   


    // attributes in every shape
    xml_shape += get_parallel_attributes(shape_num);

    // adding texture
    if ((shape.localeCompare("sphere") == 0) || (shape.localeCompare("cone") == 0)
        || (shape.localeCompare("rectangle") == 0) || (shape.localeCompare("cylinder") == 0))
    {
        var repetition = check_val((document.getElementById("repetition")));
        if (repetition.value == "")
            repetition.value = 1;

        var mapped = $('input[name=radio-207]:checked', '#mapping').val();
        if (mapped !== undefined)
        {   
            xml_shape += "\t\t\t<texture>\n";
            var temp_map = get_mapping();
            if (temp_map != 0)
                xml_shape += temp_map;
            xml_shape += "\t\t\t\t<repeat>" + repetition.value + "</repeat>\n";
            xml_shape += "\t\t\t</texture>\n";
        }
        var bumped = $('input[name=radio-208]:checked', '#bumping').val();
        if (bumped !== undefined)
        {   
            xml_shape += "\t\t\t<bump_map>\n";
            var temp_bump = get_bumping();
            if (temp_bump != 0)
                xml_shape += temp_bump;
            xml_shape += "\t\t\t\t<repeat>" + repetition.value + "</repeat>\n";
            xml_shape += "\t\t\t</bump_map>\n";
        }
    }

    xml_shape += close_shape(shape);
    var testing = "file_" + shape_num;  
    var file = document.getElementById(testing).files[0];

    console.log(xml_shape);
    if (file)
    {
        $.ajax({
            method: "POST",
            url: "http://localhost:8080/xmlwrite",
            data: { data: xml_shape, filename: file.name }
            })
            .done(function( msg ) {
            console.log( "Data Saved: " + msg );
        });
    }
    else
        console.log("No file given !");

    // this reloads file !
    // document.location.reload(true);
}

function add_shape_div() 
{
    // appends text to OBJECTS div that is the options in first part fo div, Returns the selected value.
    var sel = document.getElementById("object_options");
    var first = document.createElement("div");
    first.setAttribute("id", "chosen_shape");
    first.innerHTML =
    'You have chosen <span id="shape_chosen_text">' +
    sel.value +
    "</span> !";
    document.getElementById("objects").appendChild(first);
    return sel.value;
}

function show_shape_form(selected)
{
    // displays form for selected shape
    console.log(selected);
    var new_selected = selected + "_object";
    const string = String(new_selected);
    var show = document.getElementById(string);
    show.style.display = 'block';

    if ((selected.localeCompare("sphere") == 0) || (selected.localeCompare("cone") == 0) 
        || (selected.localeCompare("rectangle") == 0) || (selected.localeCompare("cylinder") == 0))
    {
        var textures = document.getElementById("main_textures");
        textures.style.display = 'block';
        var button = document.createElement("input");
        button.setAttribute("class", "buttons");
        button.setAttribute("id", "button_" + selected);
        button.setAttribute("type", "button");
        button.onclick = () => create_xml(selected);
        button.setAttribute("value", "ADD " + selected.toUpperCase() + " !");
        document.getElementById("the_form_container").appendChild(button);
    }
}

function select_shape_form(selected) 
{
    // creates the div that will hold the form
    const object_string = String(selected);
    var object = document.createElement("div");
    object.setAttribute("id", "object_chosen");

    if (selected.localeCompare("NO SHAPE") == 0)
    {
        object.setAttribute("class", "button_" + object_string);
        object.innerHTML = '<h3>NOTHING WILL BE <span id="selected_shape">MODIFIED</span>!</h3><br/>';
        document.getElementById("the_form_container").appendChild(object);
    } 
    else 
    {
        if (selected.localeCompare("sphere") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("cone") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("cylinder") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("plane") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("rectangle") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("box") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("triangle") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("pyramid") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("ring") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("paraboloid") == 0)
            show_shape_form(object_string);
        else if (selected.localeCompare("ellipsoid") == 0)
            show_shape_form(object_string);
    }
}

function hide_select(divsToHide)
{
    // hides the select drop down bar 
    for (var i = 0; i < divsToHide.length; i++) {
        for (var j = 0; j < divsToHide[i].childNodes.length; j++) {
            if (
            divsToHide[i].childNodes[j] &&
            divsToHide[i].childNodes[j].style
            ) {
            divsToHide[i].childNodes[j].style.visibility = "hidden";
            divsToHide[i].childNodes[j].style.display = "none";
            }
        }
    }
}

function select_object() 
{
    var header = document.getElementById("main_form_header");
    header.style.display = 'none';
    var camera = document.getElementById("camera");
    camera.style.display = 'none';
    var divsToHide = document.getElementsByClassName("objects");

    hide_select(divsToHide)
    var selected = add_shape_div();
    select_shape_form(selected);
}

function update_camera() 
{
    var divsToHide = document.getElementsByClassName("objects");
    hide_select(divsToHide);

    var header = document.getElementById("main_form_header");
    header.style.display = 'none';
    var camera = document.getElementById("camera");
    camera.style.display = 'none';
    var modify_cam = document.getElementById("modify_cam");
    modify_cam.style.display = 'block';
}

function mod_cam()
{
    var cam;
    var cam_nor = check_multi_val(document.getElementsByName('cam_normal'));
    var cam_dir = check_multi_val(document.getElementsByName('cam_direction'));
    var cam_ri = check_multi_val(document.getElementsByName('cam_right'));
    var file = document.getElementById("file_11").files[0];

    cam = "\t\t<camera>\n";
    cam += "\t\t\t<pos> " + cam_nor[2] + ", " + cam_nor[1] + ", " + cam_nor[0] + " </pos>\n";
    cam += "\t\t\t<dir> " + cam_dir[2] + ", " + cam_dir[1] + ", " + cam_dir[0] + " </dir>\n";
    cam += "\t\t\t<right> " + cam_ri[2] + ", " + cam_ri[1] + ", " + cam_ri[0] + " </right>\n";
    cam += "\t\t</camera>\n";

    if (file)
    {
        $.ajax({
            method: "POST",
            url: "http://localhost:8080/xmlcamera",
            data: { data: cam, filename: file.name }
            })
            .done(function( msg ) {
            console.log( "Data Saved: " + msg );
        });
    }
    else
        console.log("No file given !");
    return (cam);
}